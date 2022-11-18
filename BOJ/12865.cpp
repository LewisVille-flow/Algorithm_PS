/*
    17:40 ~ 18:17, 37m
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int input_weight[101] = {0, };
int input_value[101] = {0, };
int DP[101][100001];

void Init(){
    cin >> N >> K;
    
    for(int i=1; i<=N; i++)
        cin >> input_weight[i] >> input_value[i];
    
    return;
}

void Solve(){
    fill(&DP[0][0], &DP[N][N], 0);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j-input_weight[i] >= 0)
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-input_weight[i]] + input_value[i]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    cout << DP[N][K];

    return;
}

int main(){
    Init();
    Solve();
    return 0;
}
