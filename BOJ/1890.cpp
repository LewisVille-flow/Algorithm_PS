/*
    11:31~12:00, 13:28~14:24 90m
    점화식 1차
        for 반복 + 해당 i j 에서의 input 값 * 오른쪽/아래 인덱스 x, y에 대해
        dp[x][y] += 1;
        그리디..? 시간복잡도 가능??? 100 * 100 의 검색, 내부에서 쓰기작업... 2^63번 ?
        그래프가 편하지 않나 ㅋㅋ;
*/
#include <iostream>
#include <vector>
using namespace std;

class Solver{
    private:
        const static int N_MAX = 100;
        int N, start_x, start_y;
        long long answer=0;
        int grid[N_MAX][N_MAX];
        long long dp[N_MAX][N_MAX];
        int dir[2][2] = {{1, 0}, {0, 1}};

    public:
        Solver(int sx, int sy){
            this->start_x = sx;
            this->start_y = sy;
        }
        void Init();
        void dp_Init();
        bool InRange(int, int);
        void Solve();
        void Plus_New_Path(int, int);
        void Print();
        ~Solver(){}

};

bool Solver::InRange(int x, int y){
    return (x>N-1 || y>N-1) ? false:true;
}

void Solver::Init(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> grid[i][j];
    }
    fill(&dp[0][0], &dp[N+1][N+1], 0);
}

void Solver::dp_Init(){
    dp[0][0] = 1;
    //Solver::Plus_New_Path(start_x, start_y);
    return;
}

void Solver::Plus_New_Path(int x, int y){
    int _value = grid[x][y];

    for(int i=0; i<2; i++){
        int nx = x + dir[i][0]*_value;
        int ny = y + dir[i][1]*_value;

        if(InRange(nx, ny)){
            //cout << "plus: (" << nx << ", " << ny << ")\n";
            dp[nx][ny] += dp[x][y];
        }
    }
    return;
}

void Solver::Solve(){
    Solver::dp_Init();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == N-1 && j == N-1) return;
            if(dp[i][j] != 0){
                //cout << "not 1: (" << i << ", " << j << ")\n";
                Solver::Plus_New_Path(i, j);
            }
        }
    }
    return;
}

void Solver::Print(){
    answer = dp[N-1][N-1];
    cout << answer << '\n';
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    return;
}


int main(){
    int start_x = 0;
    int start_y = 0;

    Solver solver(start_x, start_y);

    solver.Init();
    solver.Solve();
    solver.Print();

    return 0;
}
