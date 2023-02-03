/*
    16:25-17:55 30m
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<long long, long long>> input;
priority_queue<long long> rooms;


void Solve(){
    cin >> N;
    int s, e;
    for(int i=0; i<N; i++){
        cin >> s >> e;
        input.push_back(make_pair(s, e));
    }
    sort(input.begin(), input.end());

    int count = 1;
    rooms.push(-input[0].second);

    for(int i=1; i<N; i++){
        if(-rooms.top() > input[i].first)
            count ++;
        else
            rooms.pop();
        rooms.push(-input[i].second);        
    }
    cout << count;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}