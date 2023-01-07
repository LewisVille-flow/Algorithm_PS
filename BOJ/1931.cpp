/*
    22:02-22:40, 40m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> lectures;

bool compare(pair<int, int>a, pair<int, int>b){
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
        return a.first < b.first;
    else
        return false;
}

void Solve(){
    cin >> N;
    for(int n=0; n<N; n++){
        int s, e;
        cin >> s >> e;
        lectures.push_back(make_pair(s, e));
    }

    sort(lectures.begin(), lectures.end(), compare);
    
    int fastest_end = lectures[0].second, answer = 1;
    
    for(int i=1; i<N; i++){
        if(lectures[i].first >= fastest_end){
            fastest_end = lectures[i].second;
            answer += 1;
        }
    }
    cout << answer;
}

int main(){
    Solve();
    return 0;
}