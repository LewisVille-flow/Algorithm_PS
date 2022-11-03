/*
    21:03~22:56 110m
    string이 익숙하지 않다
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return (a.second > b.second) ? true:false;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count[100001];
    fill(count, count+100001, 0);
    vector<pair<int, int>> temp;

    string input = s;


    char _erase_1 = '{';
    char _erase_2 = '}';
    char deliminator = ',';

    input.erase(remove(input.begin(), input.end(), _erase_1), input.end());
    //cout << input << '\n';
    input.erase(remove(input.begin(), input.end(), _erase_2), input.end());
    //cout << input << '\n';

    // getline(*inputstring, *outstring, char del);

    //
    string string_each;
    int _max = -1;
    istringstream ss(input);

    while(getline(ss, string_each, deliminator)){
        int int_each = stoi(string_each);
        count[int_each] = count[int_each] + 1;
        //cout << int_each << ' ';
        _max = max(_max, int_each);
    }

    //
    int idx, cnt;
    for(int k=1; k<=_max; k++){
        if(count[k] != 0){
            idx = k;
            cnt = count[k];
            temp.push_back(make_pair(idx, cnt));
        }
    }

    //
    sort(temp.begin(), temp.end(), compare);

    for(int j=0; j<temp.size(); j++)
        answer.push_back(temp[j].first);


    return answer;
}