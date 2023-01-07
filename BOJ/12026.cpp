/*
    20:33-21:09, 36m
*/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int _MAX = 987654321;
int N;
int dp_array[3][1001];
string input_str;

int main(){
    cin >> N >> input_str;
    fill(&dp_array[0][0], &dp_array[2][N], _MAX);
    dp_array[2][0] = 0;

    int ix, ix_before, answer = -1;
    for(int s=1; s<N; s++){
        if(input_str[s] == 'B')         ix = 2;
        else if(input_str[s] == 'O')    ix = 1;
        else if(input_str[s] == 'J')    ix = 0;

        ix_before = (ix + 1)%3;

        for(int i=s-1; i>=0; i--)
            dp_array[ix][s] = min(dp_array[ix][s], dp_array[ix_before][i] + (s-i)*(s-i));
    }

    if(dp_array[ix][N-1] != _MAX)
        answer = dp_array[ix][N-1];
    cout << answer;

    return 0;
}