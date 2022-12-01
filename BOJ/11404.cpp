/*
    16:21~16:55 34m
    같은 시작-끝 에 다른 비용의 값을 저장하게 될 수 있으므로 최소값을 저장해야 함.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

const int VALUE_MAX = INT_MAX/2 -1;
//INT_MAX               2147483647
void FindMinWageUsingFloyd(vector<vector<int>> &map, int nodeNum){
    //vector<vector<int>> FloydMap(nodeNum+1, vector<int>(nodeNum+1, VALUE_MAX));

    for(int k=1; k<=nodeNum; k++){
        for(int i=1; i<=nodeNum; i++){
            for(int j=1; j<=nodeNum; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    return;
}

void PrintAllPairWage(vector<vector<int>> &map, int nodeNum){
    for(int i=1; i<=nodeNum; i++){
        for(int j=1; j<=nodeNum; j++){
            if(i == j || map[i][j] == VALUE_MAX)
                cout << "0" << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    return;
}

void Do(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N+1, vector<int>(N+1, VALUE_MAX));

    for(int i=0; i<M; i++){
        int s, e, w;
        cin >> s >> e >> w;
        if(w < map[s][e])
            map[s][e] = w;
    }

    FindMinWageUsingFloyd(map, N);
    PrintAllPairWage(map, N);

    return;
}

int main(){
    Do();
    return 0;
}