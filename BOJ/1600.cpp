/*
    20:16-20:24, 22:18-23:55, 100m
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int W_MAX = 201, H_MAX = 201, K_MAX = 31;
int K, W, H;
int map[W_MAX][H_MAX];                      // 1 = barrier
int visited[W_MAX][H_MAX][K_MAX];           // count move number
queue<pair<pair<int, int>, int>> q;

bool InRange(int x, int y){
    return (x<0 || y<0 || x>H-1 || y>W-1) ? false:true;
}

void BFS(){
    int dir_monkey[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dir_knight[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k_num = q.front().second;
        int cnt = visited[x][y][k_num];
        q.pop();

        cout << "x, y, k_num, cnt: " << x << ", " << y << ", " << k_num << ", " << cnt << '\n';

        if(x == H-1 && y == W-1){
            cout << cnt;
            return;
        }
        for(int k=0; k<8; k++){
            int nx = x + dir_knight[k][0];
            int ny = y + dir_knight[k][1];

            if(InRange(nx, ny) && map[nx][ny] != 1){
                if(k_num+1 <= K && visited[nx][ny][k_num+1] == -1){
                    visited[nx][ny][k_num + 1] = cnt + 1;
                    q.push({{nx, ny}, k_num + 1});
                }
            }
        }
        for(int m=0; m<4; m++){
            int nx = x + dir_monkey[m][0];
            int ny = y + dir_monkey[m][1];

            if(InRange(nx, ny) && map[nx][ny] != 1){
                if(visited[nx][ny][k_num] == -1){
                    visited[nx][ny][k_num] = cnt + 1;
                    q.push({{nx, ny}, k_num});
                }
            }
        }
        
    }
    cout << -1;
}

void Solve(){
    cin >> K >> W >> H;

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            cin >> map[h][w];
        }
    }
    fill(&visited[0][0][0], &visited[H][W][K+1], -1);
    int start_x = 0, start_y = 0;


    for(int k=0; k<=K; k++)
        visited[start_x][start_y][k] = 0;
    q.push({{start_x, start_y}, 0});
    BFS();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    Solve();
    return 0;
}