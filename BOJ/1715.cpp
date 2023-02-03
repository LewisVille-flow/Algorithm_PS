/*
    17:05-17:18 13m
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
long long answer = 0;
priority_queue<int> input;

void Solve(){
    cin >> N;
    for(int n=0; n<N; n++){
        int _in;
        cin >> _in;
        input.push(-_in);
    }

    int f, s;
    for(int i=0; i<N-1; i++){
        f = -input.top(); input.pop();
        s = -input.top(); input.pop();

        answer += f+s;
        input.push(-(f + s));
    }
    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}