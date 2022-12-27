/*
    15:48-17:05 77m
    각 node로부터 연결된 모든 노드에 1 마킹
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 101;
vector<vector<int>> graph(N_MAX, vector<int>());
int grid[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];

void Solve_BFS(int node){
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        int next = q.front();
        q.pop(); 

        for(int i=0; i<graph[next].size(); i++){
            int next_adj_node = graph[next][i];

            if(!visited[node][next_adj_node]){
                visited[node][next_adj_node] = true;
                grid[node][next_adj_node] = 1;
                q.push(next_adj_node);
            }
        }
    }
    return;
}

void Solve(const int N){

    for(int i=0; i<N; i++)
        Solve_BFS(i);  

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << grid[i][j] << " ";
        cout << '\n';
    }
}

int main(){
    int N, _in; 
    cin >> N;

    fill(&grid[0][0], &grid[N-1][N], 0);
    
    for(int i=0; i<N; i++)
        memset(visited[i], false, sizeof(bool)*(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> _in;
            if(_in == 1)    graph[i].push_back(j);
        }
    }
    
    Solve(N);

    return 0;
}
