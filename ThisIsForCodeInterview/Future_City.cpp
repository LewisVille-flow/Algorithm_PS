#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

class Solver{
    private:
        const static int _N_MAX = 100;
        const int _INF = 987654321;
        int N, M, X, K, answer = 0;
        int Floyd_dist[_N_MAX+1][_N_MAX+1];
        vector<int> graph[_N_MAX+1];


    public:
        Solver(){}
        void Init();
        void Graph_Init();
        void Solve();           // Floyd Algorithm
        void Print_Answer();
        void Print_Graph();
        ~Solver(){}
};

void Solver::Init(){
    cin >> N >> M;

    int p, q;
    for(int in=0; in<M; in ++){
        cin >> p >> q;
        graph[p].push_back(q);
        graph[q].push_back(p);   
    }
    cin >> X >> K;

    Solver::Graph_Init();
    return;
}

void Solver::Graph_Init(){
    fill(&Floyd_dist[0][0], &Floyd_dist[N+1][N+1], _INF);
    
    for(int i=1; i<=N; i++)
        Floyd_dist[i][i] = 0;

    for(int j=1; j<=N; j++){
        for(int k=0; k<graph[j].size(); k++){
            int start_node = j;
            int end_node = graph[j][k];

            Floyd_dist[start_node][end_node] = 1;
        }
    }
    return;
}

// Floyd-Warshall Algorithm
void Solver::Solve(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++)
                Floyd_dist[i][j] = min(Floyd_dist[i][j], Floyd_dist[i][k]+Floyd_dist[k][j]);
        }
    }
    return;
}

void Solver::Print_Answer(){
    answer = Floyd_dist[1][K] + Floyd_dist[K][X];
    cout << answer;

    //Solver::Print_Graph();    
    return;
}

void Solver::Print_Graph(){
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cout << Floyd_dist[i][j] << " ";
        cout << '\n';
    }
    return;    
}

int main(){
    Solver solver;
    
    solver.Init();
    solver.Solve();
    solver.Print_Answer();

    return 0;
}