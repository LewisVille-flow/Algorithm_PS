/*
    15:51-16:45, 55m
*/
#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 10001;
int N;
int residence_num[N_MAX] = {0, };
int dp_array[2][N_MAX];
bool visited[N_MAX] = {false, };
vector<vector<int>> village(N_MAX, vector<int>());

void DP_Solve(int cur_node){
    dp_array[0][cur_node] = 0;
    dp_array[1][cur_node] = residence_num[cur_node];

    for(int i=0; i<village[cur_node].size(); i++){
        int next_node = village[cur_node][i];
        if(!visited[next_node]){
            visited[next_node] = true;
            DP_Solve(next_node);

            // 해당 마을을 우수 마을로 선정 x o가 i인덱스로 비교대상이 된다.
            dp_array[0][cur_node] += max(dp_array[0][next_node], dp_array[1][next_node]);
            dp_array[1][cur_node] += dp_array[0][next_node];
        }
    }
}

void Solve(){
    cin >> N;
    for(int n=1; n<=N; n++)
        cin >> residence_num[n];

    for(int vi=0; vi<N-1; vi++){
        int s, e;
        cin >> s >> e;
        village[s].push_back(e);
        village[e].push_back(s);
    }

    // 트리는 어느 노드를 루트 노드로 삼던 상관없이 트리가 형성된다. 대신 양쪽이 평형하게 안 되는 것일 뿐...
    visited[1] = true;
    DP_Solve(1);

    // 노드 n을 루트로 잡았으면 n번째 dp에 만들어지는게 최대 마을 주민수!
    cout << max(dp_array[0][1], dp_array[1][1]);
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    Solve();
    return 0;
}