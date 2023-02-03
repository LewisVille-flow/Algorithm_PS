/*
    14:15-

    long long answer
    dp_array[i] = max(dp_array[i-coin[j]])
*/
#include <iostream>

using namespace std;

const int N_MAX = 21;
const int M_MAX = 10001;
int T, N, M;

int Solve(){
    int coin[N_MAX];
    int dp_array[M_MAX];

    cin >> N;
    for(int n=0; n<N; n++)
        cin >> coin[n];
    cin >> M;

    dp_array[0] = 1;
    for(int i=0; i<N; i++){
        for(int j=coin[i]; j<=M; j++)
            dp_array[j] += dp_array[j-coin[i]];
    }
    return dp_array[M];
}

int main(){
    cin >> T;
    for(int t=0; t<T; t++)
        cout << Solve() << '\n';
    
    return 0;
}