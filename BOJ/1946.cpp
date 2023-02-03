/*
    10:28-11:10, 42m
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
vector<pair<int, int>> input;

void Solve(){
    
    cin >> T;
    for(int t=0; t<T; t++){
        int answer = 1;
        input.clear();

        cin >> N;
        
        int first, second;
        for(int n=0; n<N; n++){
            cin >> first >> second;
            input.push_back(make_pair(first, second));
        }

        //sort(input.begin(), input.end(), greater<pair<int, int>>());
        sort(input.begin(), input.end());

        int second_max = input[0].second;
        for(int i=1; i<N; i++){
            if(input[i].second < second_max){
                second_max = input[i].second;
                answer ++;
            }
        }
        
        cout << answer << '\n';        
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}