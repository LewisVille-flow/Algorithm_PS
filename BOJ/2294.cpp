/*
    17:18~19:13 120m
    아~ ==이랑 = 구분 잘하자 멍청아 ㅠ
*/
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

class Solver{
    private:
        const static int K_MAX = 10000;
        int N, K, answer=0;
        int input[K_MAX+1];
        int dp_array[K_MAX+1];
    
    public:
        Solver(){}
        void Init();
        void DP_Init();
        void Solve();
        void Print();
        ~Solver(){}
};

void Solver::Init(){
    cin >> N >> K;
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        if(in <= K) input[i] = in;
        else        input[i] = 0;
    }
    fill(dp_array, dp_array+(K+1), INT_MAX-1);
    //sort(input, input+N);
    //for(int j=0; j<N; j++)
        //cout << input[j] << " ";
    return;
}

void Solver::DP_Init(){
    for(int i=0; i<N; i++)
        dp_array[input[i]] = 1;

    //dp_array[K] = -1;

    return;
}

void Solver::Solve(){
    Solver::DP_Init();

    for(int i=0; i<N; i++){
        for(int j=input[i]+1; j<=K; j++){
            dp_array[j] = min(dp_array[j], dp_array[j-input[i]] + 1);
        }
    }
    /*
    for(int j=1; j<=K; j++)
        cout << dp_array[j] << " ";
    */
    return;
}

void Solver::Print(){
    answer = dp_array[K];

    if(answer == INT_MAX-1) answer = -1;
    cout << answer << '\n';
    return;
}


int main(){
    Solver solver;

    solver.Init();
    solver.Solve();
    solver.Print();

    return 0;
}