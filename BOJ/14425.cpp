/*
    14:26~14:46 20m
*/
#include <map>
#include <string>
#include <iostream>
using namespace std;

string input, test;
int N, M, cnt=0;
map<string, bool> _map;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> input;
        _map.insert({input, true});
    }
    for(int j=0; j<M; j++){
        cin >> test;
        if(_map[test])
            cnt ++;
    }
    cout << cnt;
    return 0;
}