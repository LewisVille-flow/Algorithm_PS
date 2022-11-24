/*
    12:20~13:30, 15:00~15:30
    100m
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, S, M;
int input[51] = {0,};
int DP[51][1001];

bool InRange(int value_before, int value_volume, char op){
    if(op == '+'){
        return (value_before + value_volume <= M) ? true:false;
    }
    else if(op == '-'){
        return (value_before - value_volume) >= 0 ? true:false;
    }
}

void Init(){
    //
    cin >> N >> S >> M;

    for(int i=0; i<N; i++)
        cin >> input[i];

    fill(&DP[0][0], &DP[N][M], 0);

    //
    if(InRange(S, input[0], '+'))
        DP[0][S+input[0]] = 1;
    if(InRange(S, input[0], '-'))
        DP[0][S-input[0]] = 1;
    return;
}

void Solve(){
    int answer = -1;
    for(int i=1; i<N; i++){
        for(int j=0; j<=M; j++){
            if(DP[i-1][j] == 1 && InRange(j, input[i], '+'))
                DP[i][j+input[i]] = 1;
            if(DP[i-1][j] == 1 && InRange(j, input[i], '-'))
                DP[i][j-input[i]] = 1;
        }
    }

    for(int m=M; m>=0; m--){
        if(DP[N-1][m] == 1){
            answer = m;
            break;
        }
    }
    /*
    for(int m=0; m<N; m++){
        for(int n=0; n<=M; n++)
            cout << DP[m][n] << " ";
        cout << '\n';
    }*/

    cout << answer;

    return;
}

int main(){

    Init();
    Solve();

    return 0;
}
