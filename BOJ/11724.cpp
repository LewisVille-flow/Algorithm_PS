/*
    20:05~20:50
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, n, q, answer = 0;
int N_max = 1000;
int M_max = int((N_max*(N_max - 1))/2);

bool visited[1001];

vector<vector<int>> graph(1001);

void DFS(int node){
    int next;

    for(int i=0; i<graph[node].size(); i++){
        next = graph[node][i];
        if(!visited[next]){
            visited[next] = true;
            DFS(next);
        }
    }

    return;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> n >> q;

        graph[n].push_back(q);
        graph[q].push_back(n);
    }
    memset(visited, false, sizeof(bool)*(N+1));

    //visited[graph[0]] = true;
    for(int j=1; j<=N; j++){
        if(!visited[j]){
            answer += 1;
            DFS(j);
        }
    }

    cout << answer << '\n';
    return 0;
}