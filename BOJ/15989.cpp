/*
    17:04~17:27 설계, 실패. 다시, !!!
    17:04 ~ 18:18, 아직 dp 어렵다.
*/

#include <iostream>
#include <cstring>

using namespace std;

int N, input;
int dp[4][10001];

void Solver(int target){
    for(int j=4; j<=target; j++){
        dp[1][j] = dp[1][j-1];
        dp[2][j] = dp[2][j-2] + dp[1][j-2];
        dp[3][j] = dp[3][j-3] + dp[2][j-3] + dp[1][j-3];
    }
    cout << dp[1][target] + dp[2][target] + dp[3][target] << '\n';
    return;
}

void dp_Init(int target){
    fill(&dp[1][1], &dp[3][target], 0);

    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            if(i == j || j > i)
                dp[i][j] = 1;
        }
    }
    return;
}

int main(){
    // init
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> input;
        dp_Init(input);
        Solver(input);
    }

    return 0;
}