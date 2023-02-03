#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T, N;
int input_up[100001];
int input_down[100001];
int dp_array[3][100001];

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        for(int up=0; up<N; up++)
            cin >> input_up[up];
        for(int dow=0; dow<N; dow++)
            cin >> input_down[dow];

        dp_array[0][0] = 0;    dp_array[1][0] = input_up[0];  dp_array[2][0] = input_down[0];
        for(int i=1; i<N; i++){
            dp_array[0][i] = max(dp_array[1][i-1], dp_array[2][i-1]);
            dp_array[1][i] = max(dp_array[0][i-1] + input_up[i], dp_array[2][i-1] + input_up[i]);
            dp_array[2][i] = max(dp_array[0][i-1] + input_down[i], dp_array[1][i-1] + input_down[i]);
        }
        cout << max(max(dp_array[0][N-1], dp_array[1][N-1]), dp_array[2][N-1]) << '\n';
    }
    return 0;
}