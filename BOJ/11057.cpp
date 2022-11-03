/*
    16:45~17:16 31m
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solver{
    private:
        const int derivate = 10007;
        const static int N_MAX = 1000;
        int N, answer;
        int dp_array[N_MAX+1][10];  // row = 수의 길이(최대 N) col = 마지막 자리 수
    
    public:
        Solver(){}
        void Init();
        void DP_Init();
        void Solve();
        void Print();
        ~Solver(){}
};

void Solver::Init(){
    cin >> N;
    fill(&dp_array[0][0], &dp_array[N][9] +1, 0);
    return;
}

void Solver::DP_Init(){
    for(int i=0; i<10; i++)
        dp_array[1][i] = 1;
    return;
}

void Solver::Solve(){
    Solver::DP_Init();

    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k>=0; k--)
                dp_array[i][j] += dp_array[i-1][k];
            dp_array[i][j] = dp_array[i][j]%derivate;
        }
    }
    return;
}

void Solver::Print(){
    for(int i=0; i<10; i++)
        answer += dp_array[N][i];
    cout << (answer%derivate);
    return;
}


int main(){
    Solver solver;

    solver.Init();
    solver.Solve();
    solver.Print();

    return 0;
}