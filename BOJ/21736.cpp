/*
    idea: dx dy search using BFS
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int grid[601][601];
bool visited[601][601] = {false, };

bool InRange(int x, int y){
    return (x<0 || x>N-1 || y<0 || y>M-1 || grid[x][y] == -1) ? false:true;
}

int Friends_BFS(int x, int y){
    queue<pair<int, int>> queue;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int cnt = 0;

    queue.push(make_pair(x, y));

    while(!queue.empty()){
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        

        for(int i=0; i<4; i++){
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];

            if(InRange(new_x, new_y) && !visited[new_x][new_y]){
                //cout << grid[new_x][new_y] << '\n';
                visited[new_x][new_y] = true;
                if(grid[new_x][new_y] == 1) cnt += 1;

                queue.push(make_pair(new_x, new_y));
            }
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1. init
    cin >> N >> M;
    int start_x, start_y;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            cin >> tmp;

            if(tmp == 'O')          grid[i][j] = 0;
            else if(tmp == 'P')     grid[i][j] = 1;
            else if(tmp == 'X')     grid[i][j] = -1;
            else if(tmp == 'I'){    grid[i][j] = 2; start_x = i; start_y = j;}
        
        }
    }

    // 2. function
    visited[start_x][start_y] = true;
    int result = Friends_BFS(start_x, start_y);

    // 3. out
    if(result == 0) cout << "TT" << '\n';
    else            cout << result << '\n';

    return 0;
}