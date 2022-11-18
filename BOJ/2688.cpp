/*
    10:45~10:57 설계
    ~11:08 작성, 오류수정
    총 23m
*/

#include <iostream>
#include <algorithm>

using namespace std;

int T;
long long dp[65][10];

void Solve(int N){
    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++)
                dp[i][j] += dp[i-1][k];
        }
    }
    return;
}

void Print(int N){
    long long answer=0;

    for(int i=0; i<10; i++)
        answer += dp[N][i];

    cout << answer << '\n';
    return;
}
void DP_Init(int N){
    fill(&dp[1][0], &dp[N][9], 0);
    
    for(int i=0; i<10; i++)
        dp[1][i] = 1;

    return;
}

int main(){
    int N;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        DP_Init(N);
        Solve(N);
        Print(N);
    }

    return 0;
}