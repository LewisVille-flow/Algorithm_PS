/*
    20:25~21:21 56m
*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool CheckIfUnmatureTomato(int row, int col, vector<vector<int>> &map){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(map[i][j] == 0)
                return true;
        }
    }
    return false;
}

bool InRange(int x, int y, int row, int col){
    return (x<0 || x>row-1 || y<0 || y>col-1) ? false:true;
}

int BFSTomato(int row, int col, vector<vector<int>> &map, queue<pair<int, int>> &tomato){
    int pushedBeforeNum = tomato.size(), pushedCurNum = 0;
    int popCnt = 0, dayCnt = 0;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while(!tomato.empty()){
        int x = tomato.front().first;
        int y = tomato.front().second;
        tomato.pop();
        popCnt += 1;

        for(int i=0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(InRange(nx, ny, row, col) && map[nx][ny] == 0){
                pushedCurNum += 1;
                map[nx][ny] = 1;
                tomato.push(make_pair(nx, ny));
            }
        }

        if(popCnt == pushedBeforeNum){
            pushedBeforeNum = pushedCurNum;
            pushedCurNum = 0;
            popCnt = 0;
            dayCnt += 1;
        }
    }
    return dayCnt;
}

int GettingMatureDayByDay(int row, int col, vector<vector<int>> &map, queue<pair<int, int>> &tomato){
    
    // exception
    if(!CheckIfUnmatureTomato(row, col, map))
        return 0;

    // BFS
    int dayCnt = BFSTomato(row, col, map, tomato);

    if(!CheckIfUnmatureTomato(row, col, map))
        return dayCnt-1;

    return -1;
}

void Do(){
    // init
    int row, col;
    cin >> col >> row;

    vector<vector<int>> map(row, vector<int>(col, 0));
    queue<pair<int, int>> PosTomato;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> map[i][j];

            if(map[i][j] == 1)
                PosTomato.push(make_pair(i, j));
        }
    }
    // Solve
    int answer = GettingMatureDayByDay(row, col, map, PosTomato);

    cout << answer;
    return;
}

int main(){
    Do();
    return 0;    
}