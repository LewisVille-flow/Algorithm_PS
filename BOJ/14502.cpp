/*
    Idea. 
        1.1 벽을 먼저 3개 세운다. 1.2 2를 채워넣는다 1.3 남는 공간 카운트 1.4 반복

    1.1 벽을 어떻게 세우느냐? 
        input N,M <= 8 이므로 최대 62칸에서 서로다른 3칸을 뽑는 경우의 수
        62*61*10(=약 40,000가지)
        + 여기서 1.2 단계, 2를 쓰고 지우는 연산은 벽을 세우는 각 가지 수에서 매번 반복.
    
        이거 틀린거같음 -> 즉 약 80,000 번의 연산이 BFS에서 진행됨. 제한 시간 2초 내에 달성 가능해보임.

        + for 문 비교연산(재귀) 64*64*64 = 약 200,000 회. 재귀로도 양호할 것으로 예상.

    1.2 2를 어떻게 퍼트릴건지도 관건. -> DFS
        퍼트리고 난 뒤 다시 복귀 -> 2로 썼다가 지우는 과정 사이에 안전지대 검색이 어려워
        memcpy로 grid 복붙 진행.

    1.3 남은 0을 어떻게 셀 것인가? - for loop
        이후 memcpy 된 grid 폐기. 다시 벽을 세우면서 전체 프로세스 반복 진행.

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;

int N, M, ans;
int** grid;
int** grid_copy;
vector<pair<int, int>> virus;
vector<int> zero_cnt;

void Count_Safety_Area(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid_copy[i][j] == 0){
                ans += 1;
            }
        }
    }
    zero_cnt.push_back(ans);
    //cout << ans << '\n';

    return;
}

bool Spread_Virus_InRange(int x, int y){
    return ( x<0 || x>N-1 || y<0 || y>M-1 || grid_copy[x][y]==1 || grid_copy[x][y]==2) ? false:true;
}

void Spread_Virus_DFS(int x, int y){
    int dir_x[4] = {-1, 0, 1, 0}; // N,E,S,W
    int dir_y[4] = {0, 1, 0, -1};

    for(int dir=0; dir<4; dir++){
        int new_x = x+dir_x[dir];
        int new_y = y+dir_y[dir];

        if(Spread_Virus_InRange(new_x, new_y)){
            grid_copy[new_x][new_y] = 2;
            Spread_Virus_DFS(new_x, new_y);
        }
    }

    return;
}

void Spread_Virus(){
    int x, y;

    for(int i=0; i<virus.size(); i++){
        x = virus[i].first;
        y = virus[i].second;
        
        Spread_Virus_DFS(x, y);
    }

    Count_Safety_Area();
    return;
}


void Create_Wall(int wall_cnt){
    // 1. End condition
    if(wall_cnt == 3){
        //cout << "wall cnt == 3" <<'\n';
        for(int a=0; a<N; a++)
            memcpy(grid_copy[a], grid[a], sizeof(int)*M);
    
        ans =0;
        Spread_Virus();
        return;
    }
    
    // 2. Brute force
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] != 1 && grid[i][j] != 2){
                // Create Wall - Backtracking
                grid[i][j] = 1;

                Create_Wall(wall_cnt +1);  // recursion -> backtracking

                grid[i][j] = 0;
            }
        }
    }
    // cout << "end of Create wall function" << '\n';
    return;
}


int main(){
    // 1. init
    cin >> N >> M;
    grid = new int*[N]; grid_copy = new int*[N];
    for(int g=0; g<N; g++){
        grid[g] = new int[M];   grid_copy[g] = new int[M];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> grid[i][j];

            // 1-1. save 2 point. it will be start point of Spread_Virus();
            if(grid[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    // 2. function start
    int wall_cnt = 0;
    Create_Wall(wall_cnt);
    
    // 3. sort answer vector and print(vector value == max 0 cnt in each cases)
    sort(zero_cnt.begin(), zero_cnt.end());

    int result = zero_cnt[zero_cnt.size()-1];
    cout << result <<'\n';
    
    return 0;
}