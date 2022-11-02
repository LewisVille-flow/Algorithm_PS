/*
    가로, 세로 input확인 잘하기..
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solver{
    private:
        const static int _MAX = 100;
        int N, M;
        int answer[2];
        int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
        char input;
        char graph[_MAX][_MAX];
        bool visited[_MAX][_MAX];
    
        queue<pair<int, int>> Queue;

        
    public:
        Solver(){}

        void Init();
        bool InRange(int i, int j);
        void Find_NumofArmy(char in);
        int Search_BFS(char in);
        void Print_Answer();

        ~Solver(){}
};

void Solver::Init(){
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> input;
            graph[i][j] = input;
        }
        memset(visited[i], false, sizeof(bool)*(M+1));
    }
    
}

bool Solver::InRange(int x, int y){
    return (x<0 || x>N-1 || y<0 || y>M-1) ? false:true;
}

void Solver::Find_NumofArmy(char in){
    char now, target_color = in;
    int color_cnt;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            now = graph[i][j];
            color_cnt = 0;

            if(!visited[i][j] && now == target_color){
                visited[i][j] = true;
                Queue.push(make_pair(i, j));
                //cout << "(" << i << ", " << j << ")\n";
                color_cnt = Search_BFS(target_color);
                color_cnt *= color_cnt;
            }
            if(target_color == 'W')       answer[0] += color_cnt;
            else if(target_color == 'B')  answer[1] += color_cnt;
        }
    }
    return;
}

int Solver::Search_BFS(char in){
    int x, y, result = 0;
    char target_color = in;

    while(!Queue.empty()){
        result += 1;
        x = Queue.front().first;
        y = Queue.front().second;
        Queue.pop();

        for(int d=0; d<4; d++){
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if(InRange(nx, ny) && !visited[nx][ny] && graph[nx][ny] == target_color){
                visited[nx][ny] = true;
                Queue.push(make_pair(nx, ny));
            }
        }
    }
    return result;
}

void Solver::Print_Answer(){
    for(int i=0; i<sizeof(answer)/sizeof(*answer); i++){
        cout << answer[i] << " ";
    }
}

int main(){
    Solver solve;

    solve.Init();

    solve.Find_NumofArmy('W');
    solve.Find_NumofArmy('B');
    
    solve.Print_Answer();

    return 0;
}