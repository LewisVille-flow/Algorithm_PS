/*
    16:03-16:19, 16m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> input;

void Solve(){
    cin >> N >> M;
    for(int n=0; n<N; n++){
        int _in;
        cin >> _in;
        input.push_back(_in);
    }

    long long sum = 0;
    for(int m=0; m<M; m++){
        sort(input.begin(), input.end());
        sum = input[0] + input[1];
        input[0] = sum;
        input[1] = sum;
    }

    long long answer = 0;
    for(int i=0; i<N; i++)
        answer += input[i];
    
    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}