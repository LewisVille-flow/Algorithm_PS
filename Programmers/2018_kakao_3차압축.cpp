/*
    1차 15:49-17:01 .... ㅠㅡㅠ
    2차 20:16-20:39
*/
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    int value;
    
    // 1. A to Z in map
    for(int i=0; i<26; i++){
        string alphabet = "";
        alphabet += (i + 65);
        dict[alphabet] = i + 1;
    }
    // 2. LZW
    for(int i=0; i<msg.size();){
        string now = "";
        now += msg[i];
        
        while(i<msg.size() && dict[now] != 0){
            value = dict[now];
            now += msg[++i];
        }
        dict[now] = dict.size();
        answer.push_back(value);
    } 
    return answer;
}


/*
// 1차 풀이
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dictionary;
    
    for(int i=0; i<26; i++){
        char n = 'A' + i;
        string now = "";
        now.push_back(n);
        dictionary[now] = i+1;
    }
    
    int m = 0;
    while(m<msg.size()){
        string tmp = "";
        tmp.push_back(msg[m]);
        //string c(msg[m]);
        //tmp.append(c);
        cout << "tmp: " << tmp;
        int value = dictionary[tmp];
        
        int n = m+1;
        for(n; n<msg.size() && dictionary[tmp] != 0; n++){
            value = dictionary[tmp];
            tmp += msg[n];
        }
        if(n == msg.size() && dictionary[tmp] != 0)
            value = dictionary[tmp];
        
        if(dictionary[tmp] == 0){
            cout << " not in here: " << tmp << ", " << dictionary.size();
            dictionary[tmp] = dictionary.size();
            if(tmp.size() > 1)
                m += tmp.size() - 1;
            else
                m ++;
        }
        else
            m += tmp.size();
        cout << ", " << tmp.size() << ", " << m << ", " << value;
        answer.push_back(value);
       
        
        cout << '\n';
    }
    return answer;
}
*/