/*
    21:09-21:58, 50m
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N_MAX = 1000001;
int T, N;
vector<int> input;
vector<pair<int, int>> compare;

void Solve(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        input.clear();
        compare.clear();

        for(int i=0; i<N; i++){
            int _in;
            cin >> _in;
            input.push_back(_in);
        }
        
        int _max = -1;
        long long answer = 0;
        for(int i=N-1; i>=0; i--){
            _max = max(_max, input[i]);
            answer += _max - input[i];
        }

        cout << answer << '\n';
    }
}

int main(){
    Solve();
    return 0;
}