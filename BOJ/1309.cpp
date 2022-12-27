/*
    10:58-11:39, 41m.
*/
#include <iostream>

using namespace std;

const int N_MAX = 100000;
const int DIV = 9901;
int N;

int main(){
    //
    int dp_array[3][N_MAX];
    cin >> N;

    //
    dp_array[0][1] = 1;
    dp_array[1][1] = 1;
    dp_array[2][1] = 1;

    for(int i=2; i<=N; i++){
        dp_array[0][i] = (dp_array[2][i-1] + dp_array[1][i-1])%DIV;
        dp_array[1][i] = (dp_array[2][i-1] + dp_array[0][i-1])%DIV;
        dp_array[2][i] = (dp_array[0][i-1] + dp_array[1][i-1] + dp_array[2][i-1])%DIV;
    }
    
    cout << (dp_array[0][N] + dp_array[1][N] + dp_array[2][N])%DIV;

    return 0;    
}