/*
    20:58~22:53 ...
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, M, n, q;
vector<vector<int>> graph(10001);
int array_cnt[10001];
int cnt = 0;
int hack_max = INT_MIN;
bool visited[10001];

void DFS(int cur_node){
    int next_node;
    
    for(int i=0; i<graph[cur_node].size(); i++){
        next_node = graph[cur_node][i];

        if(!visited[next_node]){
            cnt += 1;
            visited[next_node] = true;
            DFS(next_node);
        }
    }
    
    return;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> n >> q;
        graph[q].push_back(n);
    }
    memset(array_cnt, 0, sizeof(int)*(N+1));
    
    for(int l=1; l<=N; l++){
        cnt = 0;
        memset(visited, false, sizeof(bool)*(N+1));
        visited[l] = true;
        DFS(l);
        array_cnt[l] = cnt;
        hack_max = max(hack_max, array_cnt[l]);
    
    }


    for(int k=1; k<=N; k++){
        if(array_cnt[k] == hack_max)
            cout << k << " ";
    }
    cout << "\n";

/*
    for(int m=1; m<=N; m++)
        cout << array_cnt[m] << " ";
*/
    return 0;
}