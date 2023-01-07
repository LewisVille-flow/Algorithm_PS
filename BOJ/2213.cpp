/*
    17:38-18:34, 56m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 10001;
int N;
int node_value[N_MAX];
int dp_array[2][N_MAX];
vector<vector<int>> tree(N_MAX, vector<int>());
vector<int> answer_set;
bool visited[N_MAX] = {false, };
bool backtrack_visited[N_MAX] = {false, };

void Node_Search(int cur_node, bool before){
    if((dp_array[0][cur_node] < dp_array[1][cur_node]) && !before){
        answer_set.push_back(cur_node);
        before = true;
    }
    else
        before = false;
    
    for(int i=0; i<tree[cur_node].size(); i++){
        int next_node = tree[cur_node][i];
        if(!backtrack_visited[next_node]){
            backtrack_visited[next_node] = true;
            Node_Search(next_node, before);
        }
    }
}

void DP_Solve(int cur_node){
    dp_array[0][cur_node] = 0;
    dp_array[1][cur_node] = node_value[cur_node];

    for(int i=0; i<tree[cur_node].size(); i++){
        int next_node = tree[cur_node][i];
        if(!visited[next_node]){
            visited[next_node] = true;
            DP_Solve(next_node);            // 일단 먼저 재귀적 호출. leaf node까지 가도록.

                                            // 리턴 후 해당 노드의 인접 노드들과 비교 후 계산
            dp_array[0][cur_node] += max(dp_array[0][next_node], dp_array[1][next_node]);
            dp_array[1][cur_node] += dp_array[0][next_node];
        }
    }
}

void Solve(){
    cin >> N;
    for(int n=1; n<=N; n++)
        cin >> node_value[n];

    for(int i=0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    fill(&dp_array[0][0], &dp_array[1][N+1], 0);

    // 임의의 노드로 트리 부모를 설정하고 서치
    visited[1] = true;
    DP_Solve(1);

    // 독립 집합에 속하는 정점 서치
    backtrack_visited[1] = true;
    Node_Search(1, false);
    sort(answer_set.begin(), answer_set.end());

    cout << max(dp_array[0][1], dp_array[1][1]) << '\n';

    for(int a=0; a<answer_set.size(); a++)
        cout << answer_set[a] << " ";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}