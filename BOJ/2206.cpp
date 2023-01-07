/*
    start at 16:50 finished at 18:25 (95m)

    idea: bfs, queue, visit + condition
    특정 지점에 벽을 뚫고 도착한게 bfs 특성상 빠르다면, 더이상 진행하지 못하고 종료됨.
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, answer = -1;          // end point = N-1, M-1
int grid[1001][1001];
queue<pair<pair<int, int>, int>> Queue;
bool visited[1001][1001];
bool cross_wall[1001][1001];

bool InRange(int x, int y){
    return (x<0 || x>N-1 || y<0 || y>M-1) ? false:true;
}

void Move(){
    int x, y, cnt, _wall;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while(!Queue.empty()){
        x = Queue.front().first.first;
        y = Queue.front().first.second;
        cnt = Queue.front().second;
        //_wall = Queue.front().second.second;
        _wall = cross_wall[x][y];
        Queue.pop();

        //cout << "now: (" << x << ", " << y << ", " << cnt << ", " << _wall << ")";

        if(x == N-1 && y == M-1){
            answer = cnt;
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(!InRange(nx, ny))
                continue;
            
            if(grid[nx][ny] == 0 && !visited[nx][ny]){  
                visited[nx][ny] = true;
                cout << " found 0: (" << nx << ", " << ny << ", " << cnt << ", " << _wall << ")";
                //cross_wall[nx][ny] = 0;
                cross_wall[nx][ny] = _wall;
                Queue.push(make_pair(make_pair(nx, ny), cnt+1));
            }
            else if(grid[nx][ny] == 1 && !visited[nx][ny] && _wall == false){
                visited[nx][ny] = true;
                cout << " found 1: (" << nx << ", " << ny << ", " << cnt << ", " << _wall << ")";
                cross_wall[nx][ny] = true;
                Queue.push(make_pair(make_pair(nx, ny), cnt+1));
            }
            
            /*
            // 이미 방문했다면 벽 뚫지 않고도 가는 방법을 무시하게 되므로, 추가하였음.
            else if(grid[nx][ny] == 0 && visited[nx][ny] && cross_wall[nx][ny] == true && _wall == false){
                cout << " update wall: (" << nx << ", " << ny << ", " << cnt << ", " << _wall << ")";
                cross_wall[nx][ny] = false;
                Queue.push(make_pair(make_pair(nx, ny), cnt+1));
            }
            */
            
            //else
                //cout << " return" << '\n';
        }
        cout << '\n';
    }
    
    return;
}

int main(){
    // 1. init
    char in;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> in;
            grid[i][j] = in - '0';
        }
        memset(visited[i], false, sizeof(bool)*M);
        memset(cross_wall[i], false, sizeof(bool)*M);
    }

    // 2. function
    // x, y, cnt, if wall
    Queue.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = true;
    Move();

    // 3. out
    cout << answer << '\n';

    return 0;
}