/*
    16:04-16:29, 25m
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int input[301] = {0, };
int dp_array[2][301] = {0, };

void Solve(){
    cin >> N;
    for(int n=0; n<N; n++)
        cin >> input[n];

    dp_array[0][0] = input[0], dp_array[1][0] = 0;
    dp_array[0][1] = input[1], dp_array[1][1] = input[0] + input[1];

    for(int d=2; d<N; d++){
        dp_array[0][d] = max(dp_array[0][d-2] + input[d], dp_array[1][d-2] + input[d]);
        dp_array[1][d] = dp_array[0][d-1] + input[d];
    }

    cout << max(dp_array[0][N-1], dp_array[1][N-1]);
}

int main(){
    Solve();
    return 0;
}