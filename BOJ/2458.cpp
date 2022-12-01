/*
    16:56~17:34 40m
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int VALUE_MAX = INT_MAX/2 -1;

void Floyd(vector<vector<int>> &map, int studentNum){
    for(int k=1; k<=studentNum; k++){
        for(int i=1; i<=studentNum; i++){
            for(int j=1; j<=studentNum; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
        }
    }
    return;
}

void FindNumOfStudent(vector<vector<int>> &map, int studentNum){
    int answer = 0;
    // calculate shortest value
    Floyd(map, studentNum);

    for(int i=1; i<=studentNum; i++){
        int cnt = 0;
        for(int j=1; j<=studentNum; j++){
            if(map[i][j] != VALUE_MAX || map[j][i] != VALUE_MAX)
                cnt += 1;
            //cout << cnt << '\n';
        }
        if(cnt == studentNum-1)
            answer += 1;
    }

    cout << answer;
    return;
}

void Solve(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> map(N+1, vector<int>(N+1, VALUE_MAX));

    for(int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        map[s][e] = 1;
    }

    FindNumOfStudent(map, N);
}

int main(){
    Solve();

    return 0;
}