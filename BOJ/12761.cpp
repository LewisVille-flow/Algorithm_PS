/*
    19:57-20:15 17m
*/
#include <iostream>
#include <queue>

using namespace std;

const int N_MAX = 100001;
bool visited[100001] = {false, };
queue<pair<int, int>> q;
int A, B, N, M;

bool InRange(int num){
    return (num < 0 || num >= N_MAX) ? false:true;
}

void PushInQueue(int next, int cnt){
    if(InRange(next) && !visited[next]){
        visited[next] = true;
        q.push(make_pair(next, cnt+1));
    }
}

int main(){
    cin >> A >> B >> N >> M;
    
    visited[N] = true;
    q.push(make_pair(N, 0));

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == M){
            cout << cnt;
            break;
        }

        int next;
        // -1
        next = cur -1;
        PushInQueue(next, cnt);
        // +1
        next = cur + 1;
        PushInQueue(next, cnt);
        // +A
        next = cur + A;
        PushInQueue(next, cnt);
        // -A
        next = cur - A;
        PushInQueue(next, cnt);

        next = cur + B;
        PushInQueue(next, cnt);

        next = cur - B;
        PushInQueue(next, cnt);

        next = cur * A;
        PushInQueue(next, cnt);

        next = cur * B;
        PushInQueue(next, cnt);
    }
    return 0;
}