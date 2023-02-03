/*
    17:19-17:34, 18:00-19:25 100m
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer[1001] = {0, };
priority_queue<pair<int, int>> input;


void Solve(){
    cin >> N;
    for(int n=0; n<N; n++){
        int s, e;
        cin >> s >> e;
        input.push(make_pair(e, s));
    }
    
    for(int i=0; i<N; i++){
        for(int j=input.top().second; j>0; j--){
            if(answer[j] == 0){
                answer[j] = input.top().first;
                break;
            }
        }
        input.pop();
    }

    int result = 0;
    for(int a=0; a<1001; a++)
        result += answer[a];

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    Solve();
    return 0;
}