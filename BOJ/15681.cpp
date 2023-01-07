/*
    14:30-15:35, 함수 리턴형 잘못해서 헤맸다 ㅠㅠ
*/
#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 100001;
int vertex_num, root_node, query_num;
int dp_array[N_MAX] = {0, };
bool visited[N_MAX] = {false, };
vector<vector<int>> tree(N_MAX, vector<int>());

int DP_Init(int cur_node){
    // recursively call
    dp_array[cur_node] = 1;

    //if(tree[cur_node].size() == 1)
    //    return dp_array[cur_node];      
    
    for(int i=0; i<tree[cur_node].size(); i++){
        int next_node = tree[cur_node][i];

        if(!visited[next_node]){
            visited[next_node] = true;
            dp_array[cur_node] += DP_Init(next_node);
        }
    }
    return dp_array[cur_node];
}

void Solve(){
    int _a, _b;
    cin >> vertex_num >> root_node >> query_num;

    for(int v=0; v<vertex_num-1; v++){
        cin >> _a >> _b;
        tree[_a].push_back(_b);
        tree[_b].push_back(_a);
    }

    visited[root_node] = true;
    DP_Init(root_node);

    int _in;
    for(int n=0; n<query_num; n++){
        cin >> _in;
        cout << dp_array[_in] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    Solve();
    return 0;
}
