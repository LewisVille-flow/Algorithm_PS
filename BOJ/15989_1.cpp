/*
    복습
*/
#include <iostream>
#include <cstring>

using namespace std;

int N, S, M;
int dp_array[51][1001];
int input[51];

bool InRange(int i){
    return (i<0 || i>M) ? false:true;
}

void Solve(){
    cin >> N >> S >> M;
    for(int n=0; n<N; n++)
        cin >> input[n];

    fill(&dp_array[0][0], &dp_array[N][M+1], 0);
    dp_array[0][S] = 1;
    

    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(dp_array[i-1][j] == 1){
                if(InRange(j + input[i-1]))
                    dp_array[i][j+input[i-1]] = 1;
                if(InRange(j - input[i-1]))
                    dp_array[i][j-input[i-1]] = 1;
            }
        }
    }

    for(int a=M; a>=0; a--){
        if(dp_array[N][a] == 1){
            cout << a;
            return;
        }
    }
    cout << -1;
}


int main(){
    Solve();
    return 0;
}