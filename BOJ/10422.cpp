/*
    21:04-22:05
*/
#include <iostream>

using namespace std;

int T, L;
long long dp_array[5001] = {0, };

void DP_Init(){
    dp_array[0] = 1, dp_array[2] = 1;

    for(int d=4; d<5001; d++){
        if(d%2 != 0)
            dp_array[d] = 0;
            
        else{
            for(int i=0; i<=d-2; i+=2){
                dp_array[d] += dp_array[i] * dp_array[d-2-i];
                dp_array[d] %= 1000000007;
            }
        }
    }
}

void Solve(){
    cin >> T;

    DP_Init();

    for(int t=0; t<T; t++){
        cin >> L;
        cout << dp_array[L] << '\n';
    }
}

int main(){
    Solve();
    return 0;
}