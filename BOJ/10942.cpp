/*
    11:10~12:01
    12:55~13:30 85m
*/
#include <iostream>
#include <algorithm>

using namespace std;

int T, M;
int input[2001];
bool dp[2001][2001];

void DP_init(){
    fill(&dp[1][0], &dp[T][T], false);
    
    for(int i=1; i<=T; i++)
        dp[i][i] = true;   
    
    for(int j=1; j<T; j++)
        dp[j][j+1] = (input[j] == input[j+1]) ? true:false;

    return;
}

void DP_Solve(){
    for(int i=T-2; i>=1; i--){
        for(int j=i+2; j<=T; j++){
            dp[i][j] = ((dp[i+1][j-1] == true) && (input[i] == input[j])) ? true:false;
        }
    }
    return;
}

void Start(){
    cin >> T;
    
    for(int i=1; i<=T; i++)
        cin >> input[i];

    DP_init();
    DP_Solve();

    int start, end;
    cin >> M;
    for(int j=0; j<M; j++){
        cin >> start >> end;
        cout << dp[start][end] << '\n';
    }

    return;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Start();

    return 0;
}