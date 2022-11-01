/*
    23:05~23:45
    
    exception
        다시 돌아가는 것은 고려하지 않아야 함 -> visited 사용
        최단거리를 보장하려면 BFS 여야 할 것 같다.
    
    + 단방향이다
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K, X, n, q;
const int N_MAX = 300001;

vector<int> graph[N_MAX];
vector<int> answer;
queue<pair<int, int>> Queue;

bool visited[N_MAX];

void BFS(){
    int cur_node, next_node, cnt;
    
    while(!Queue.empty()){
        cur_node = Queue.front().first;
        cnt = Queue.front().second;
        Queue.pop();
        //cout << "( " << cur_node << ", " << cnt << ")\n";

        if(cnt == 0){
            answer.push_back(cur_node);
            continue;
        }

        for(int i=0; i<graph[cur_node].size(); i++){
            next_node = graph[cur_node][i];
            
            if(!visited[next_node]){
                visited[next_node] = true;
                Queue.push(make_pair(next_node, cnt-1));
            }
        }            
    }

    return;
}

int main(){
    cin >> N >> M >> K >> X;

    for(int i=0; i<M; i++){
        cin >> n >> q;
        graph[n].push_back(q);
        //graph[q].push_back(n);
    }
    memset(visited, false, sizeof(bool)*(N+1));

    Queue.push(make_pair(X, K));
    visited[X] = true;
    BFS();

    if(answer.size() != 0){
        sort(answer.begin(), answer.end());
        for(int j=0; j<answer.size(); j++)
            cout << answer[j] << '\n';
    }
    else
        cout << "-1" << '\n';

    return 0;
}