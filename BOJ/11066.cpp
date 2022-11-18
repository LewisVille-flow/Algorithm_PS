/*
    09:50~10:30, 13:30~15:30
    160m
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int T, N;
int input_novel[501];
int sum[501];
int dp[501][501];

void Init(){
    cin >> N;
    fill(input_novel, input_novel+(N+1), 0);
    fill(sum, sum+(N+1), 0);
    fill(&dp[1][1], &dp[N][N], INT_MAX);

    for(int j=1; j<=N; j++){
        cin >> input_novel[j];
        sum[j] = sum[j-1] + input_novel[j];
    }
    return;
}

void DP_Init(){
    for(int i=1; i<=N; i++)
        dp[i][i] = 0;
    return;
}

void Print(){
    cout << dp[1][N] << '\n';
    return;
}

void Solve(){
    for(int gap=1; gap<N; gap++){            // gap
        for(int i=1; i+gap<=N; i++){         // (sum) from j
            int j = i+gap;

            for(int m=i; m+1<=j; m++)          // (sum) to j
                dp[i][j] = min(dp[i][j], (dp[i][m] + dp[m+1][j]  + (sum[j] - sum[i-1])));
        }
    }
    return;
}

int main(){
    cin >> T;

    for(int i=0; i<T; i++){
        Init();
        DP_Init();
        Solve();
        Print();
    }
    return 0;
}