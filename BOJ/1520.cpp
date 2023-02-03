/*
    15:46-17:50
    - 경로의 개수 구하기 -> BFS visited, queue <x,y>
    - '낮은 곳으로'
    - answer 1000000000 -> int
    흠, 골드 3에 DP + 그래프? 왜 그래프로만 분류가 안 된거지?
    -- 일반적인 graph bfs 의 경우 visited가 아닌 height 차이로 이동하게 되는데 이것은 시간초과를 만든다.

    dp라고 하니까 코드트리 때 풀었던 것 중 생각나는 게 있군... 2차원 그래프 느낌이었는데말야
    먼저 i=0, j=0 인 dp array를 초기화(높이가 낮아지는경우만1)하고
    dp_array[i][j] = dp_array[i-1][j] + dp_array[i][j-1], if now height < before height
    ... 이 방식도 틀렸다

    dp + graph -> dp 배열을 완성하는 데 그래프 서치를 쓴다
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int M, N;
int grid[501][501];
int dp_array[501][501];
bool visited[501][501];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool InRange(int x, int y){
    return ( x<0 || x>M-1 || y<0 || y>N-1) ? false:true;
}

// 함수 = Top-down 방식으로 접근한다. 해당 지점 상하좌우에 낮은 지점이 있다면, 그 지점에서의 경로값(=dp)을 리턴한다.
// 해당 지점의 dp 값은 상하좌우의 낮은 지점에서의 dp 값을 합친 것과 같다.
int DFS_v1(int x, int y){
    // end condition
    if(x == M-1 && y == N-1)        return 1;
    if(visited[x][y])               return dp_array[x][y];

    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(InRange(nextx, nexty) && grid[nextx][nexty] < grid[x][y])
            dp_array[x][y] += DFS(nextx, nexty);
    }
    return dp_array[x][y];    
}

int Solve(){
    int answer = 0;
    cin >> M >> N;
    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++)
            cin >> grid[m][n];
        memset(visited, false, sizeof(bool)*N);
    }
    fill(&dp_array[0][0], &dp_array[M-1][N], 0);

    //dp_array[0][0] = 1;
    answer = DFS(0, 0);

    /*

    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0,0});

    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        cout << "now: " << nowx << ", " << nowy << " ";
        if(nowx == M-1 && nowy == N-1){
            break;
        }

        for(int i=0; i<4; i++){
            int nextx = nowx + dir[i][0];
            int nexty = nowy + dir[i][1];

            if(InRange(nextx, nexty) && !visited[nextx][nexty] && grid[nextx][nexty] < grid[nowx][nowy]){
                visited[nextx][nexty] = true;
                dp_array[nextx][nexty] += dp_array[nowx][nowy];
                q.push({nextx, nexty});
                cout << nextx << ", " << nexty << ", " << dp_array[nextx][nexty] << '\n';
            }
        }
    }

    */

    /*

    // 일반적인 dp 는 이동이 오른쪽, 아래 방향일 때만 적용 가능하다.
    for(int m=1; m<M; m++){
        for(int n=1; n<N; n++){
            if(grid[m][n] < grid[m-1][n])
                dp_array[m][n] += dp_array[m-1][n];
            if(grid[m][n] < grid[m][n-1])
                dp_array[m][n] += dp_array[m][n-1];
        }
    }
    */

    /*
    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++)
            cout << dp_array[m][n] << " ";
        cout << '\n';
    }
    
    answer = dp_array[M-1][N-1];
    */
    return answer;
}

int main(){
    int answer = Solve();
    cout << answer;
    return 0;
}