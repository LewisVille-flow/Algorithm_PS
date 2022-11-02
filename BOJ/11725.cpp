/*
    11:15~11:42
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solver{
    
    private:
        const static int N_MAX = 100001;
        int N;
        int start_node = 1;
        bool visited[N_MAX];
        int parent[N_MAX];
        vector<int> graph[N_MAX];
        queue<int> node_queue;
    
    public:
        Solver(){}

        void Init();
        void BFS(int node);
        void Print_Answer();

        ~Solver(){}
};

void Solver::Print_Answer(){
    for(int i=2; i<=N; i++)
        cout << parent[i] << '\n';
    return;
}

void Solver::BFS(int node){
    visited[node] = true;
    node_queue.push(node);

    int cur_node, next_node;
    while(!node_queue.empty()){
        cur_node = node_queue.front();
        node_queue.pop();
        
        for(int i=0; i<graph[cur_node].size(); i++){
            next_node = graph[cur_node][i];
            //cout << "now: (" << cur_node << ", " << next_node << ")\n";

            if(!visited[next_node]){
                visited[next_node] = true;
                parent[next_node] = cur_node;

                node_queue.push(next_node);
            }
        }
    }
    return;
}

void Solver::Init(){
    cin >> N;
    int p, q;
    for(int i=0; i<N-1; i++){
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    memset(visited, false, sizeof(bool)*(N+1));
    memset(parent, 0, sizeof(int)*(N+1));

    return;
}


int main(){

    Solver solver;

    solver.Init();
    solver.BFS(1);
    solver.Print_Answer();

    return 0;
}