/*
    15:05-16:20
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 100001;
int N, M;
bool visited[N_MAX] = {false, };
int depth[N_MAX] = {0, };
int parent[N_MAX][31];
vector<vector<int>> tree(N_MAX, vector<int>());

void DFS(int n, int d){
    depth[n] = d;

    for(int i=0; i<tree[n].size(); i++){
        int next_node = tree[n][i];

        if(!visited[next_node]){
            visited[next_node] = true;
            
            parent[next_node][0] = n;
            DFS(next_node, d+1);
        }
    }
}

// parent[u][t] = 노드u 의 2^t번째 조상. tree의 값이 저장되어있어야 함.
void Make_Parent(){
    //parent[1][0] = -1;
    for(int t=1; t<=30; t++){
        for(int u=1; u<=N; u++){
            parent[u][t] = parent[ parent[u][t-1] ][t-1];
        }
    }
}

int LCA(int u, int v){
    int diff;

    if(depth[u] < depth[v]) swap(u, v);
    diff = depth[u] - depth[v];

    for(int i=0; diff; i++){
        if(diff & 1)    u = parent[u][i];    // diff & 1을 통해 맨 오른쪽 2진수 비교.
        diff >>= 1;                          // 1과 동일하다면 2^i 만큼 부모로 올려야함.(총합 diff 만큼 올린다)
    }
    if(u == v)          return u;

    for(int p=30; p>=0; p--){
        if(parent[u][p] != parent[v][p]){
            u = parent[u][p];
            v = parent[v][p];
        }
    }
    return parent[u][0];
}

void Solve(){
    cin >> N;
    for(int n=0; n<N-1; n++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    DFS(1, 0);
    Make_Parent();

    cin >> M;
    for(int m=0; m<M; m++){
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}