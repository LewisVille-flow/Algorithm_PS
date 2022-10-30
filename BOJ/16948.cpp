/*
    18:25~19:00 20:20~20:50
    간단한 dx dy BFS 문제.
    // BFS 라면 해당 좌표로 이동하는 데 걸린 시간은 최소이다.
    // 따라서 Value값이 더 작은가? 를 기준이 아닌 visited 로 bool 값을 저장해도 된다.
                
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int N;
int start_x, start_y, end_x, end_y;
queue<pair<int, int>> Queue;

int Value[201][201];
bool visited[201][201];

bool InRange(int x, int y){
    return (x<0 || x>N-1 || y<0 || y>N-1) ? false:true;
}

void Search(){  
    int x, y, value, nx, ny;

    int dir[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

    while(!Queue.empty()){
        x = Queue.front().first;
        y = Queue.front().second;
        Queue.pop();

        if(x == end_x && y == end_y)    
            break;

        for(int d=0; d<6; d++){
            nx = x+dir[d][0];
            ny = y+dir[d][1];
            value = Value[x][y];

            if(InRange(nx, ny) && !visited[nx][ny]){
                //if(Value[nx][ny] > (value + 1)){
                visited[nx][ny] = true;
                Value[nx][ny] = value + 1;
                
                Queue.push(make_pair(nx, ny));
            }
        }
    }
    return;
}


int main(){
    // 1. init
    cin >> N;
    cin >> start_x >> start_y >> end_x >> end_y;
    
    fill(&Value[0][0], &Value[N][N], 401);
    for(int i=0; i<N; i++)
        memset(visited[i], false, sizeof(bool)*N); 

    // 2. function
    Value[start_x][start_y] = 0;
    visited[start_x][start_y] = 0;
    Queue.push(make_pair(start_x, start_y));
    Search();

    // 3. out
    int result = Value[end_x][end_y];
    if(result == 401) result = -1;
    cout << result << '\n';

    return 0;
}
