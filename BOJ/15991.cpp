/*
    14:50-15:38, 48m
*/
#include <iostream>

using namespace std;

int T;
long long dp_array[100001];

void DP_init(){
    dp_array[0] = 0;
    dp_array[1] = 1, dp_array[2] = 2, dp_array[3] = 2;
    dp_array[4] = 3, dp_array[5] = 3, dp_array[6] = 6;
    for(int d=7; d<=100001; d++)
        dp_array[d] = (dp_array[d-2] + dp_array[d-4] + dp_array[d-6])%1000000009;
}

void Solve(){
    int in;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> in;
        cout << dp_array[in] << '\n';
    }
}

int main(){
    DP_init();
    Solve();
    return 0;
}