/*
    10:51-11:19 28m
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool InRange(int x, int N){
    return (x <= 0 || x > N) ? false:true;
}

void Solve(vector<vector<int>> &teleport, int S, int E, const int N){
    queue<pair<int, int>> q;
    bool visited[N+1];
    memset(visited, false, sizeof(bool)*(N+1));

    visited[S] = true;
    q.push(make_pair(S, 0));

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == E){
            cout << cnt;
            return;
        }

        int next;
        // x-1
        next = cur -1;
        if(InRange(next, N) && !visited[next]){
            visited[next] = true;
            q.push(make_pair(next, cnt+1));
        }

        // x+1
        next = cur +1;
        if(InRange(next, N) && !visited[next]){
            visited[next] = true;
            q.push(make_pair(next, cnt+1));
        }

        // 연결지점
        for(unsigned int i=0; i<teleport[cur].size(); i++){
            next = teleport[cur][i];

            if(InRange(next, N) && !visited[next]){
                visited[next] = true;
                q.push(make_pair(next, cnt+1));
            }
        }

    }

    return;
}

int main(){
    int N, M, S, E;
    cin >> N >> M >> S >> E;

    int posX, posY;
    vector<vector<int>> teleport(N+1, vector<int>());
    for(int m=0; m<M; m++){
        cin >> posX >> posY;
        teleport[posX].push_back(posY);
        teleport[posY].push_back(posX);
    }

    Solve(teleport, S, E, N);

    return 0;
}