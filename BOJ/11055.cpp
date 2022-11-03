/*
    10:35 ~ 11:27 52m
    점화식
        dp[i] = max(dp[j]+input[i]), 0<= j <= i-1
    점화식 수정
        i에 대해 0~i-1 dp 값 중 가장 큰 dp[j] + input[i]가 dp[i].
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solver{
    private:
        const static int N_MAX = 1000;
        int N, answer=0;
        int dp_array[N_MAX];
        int input_array[N_MAX];

    public:
        Solver(){}
        void Init();
        void Solve();
        void dp_Init();
        void Print();
        ~Solver(){}

};

void Solver::Init(){
    cin >> N;
    fill(dp_array, dp_array+N, 0);

    int in;

    for(int i=0; i<N; i++){
        cin >> in;
        input_array[i] = in;
    }

    return;
}

void Solver::dp_Init(){
    for(int i=0; i<N; i++){
        dp_array[i] = input_array[0];
    }
    return;
}

void Solver::Solve(){
    Solver::dp_Init();

    for(int i=1; i<N; i++){
        int _dp_max = 0;
        for(int j=0; j<i; j++){

            if(input_array[i] > input_array[j])
                _dp_max = max(_dp_max, dp_array[j]);
            
        }
        dp_array[i] = _dp_max + input_array[i];
    }
    return;
}

void Solver::Print(){
    for(int i=0; i<N; i++)
        answer = max(answer, dp_array[i]);
    cout << answer;
    /*
    for(int j=0; j<N; j++)
        cout << " " << dp_array[j] << " ";
    */
    return;
}

int main(){
    Solver solver;

    solver.Init();
    solver.Solve();
    solver.Print();

    return 0;
}