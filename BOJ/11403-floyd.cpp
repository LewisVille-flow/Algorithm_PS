#include <iostream>
#include <algorithm>

using namespace std;
const int N_MAX = 101;
const int INF = 9999;
int grid[N_MAX][N_MAX];

void Floyd_Washall(int size){
    for(int bridge=0; bridge<size; bridge++){
        for(int s=0; s<size; s++){
            for(int e=0; e<size; e++)
                grid[s][e] = min(grid[s][e], grid[s][bridge] + grid[bridge][e]);
        }
    }
    return;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 0)     grid[i][j] = INF;
        }
    }

    Floyd_Washall(N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == INF)       cout << "0" << " ";
            else                        cout << "1" << " ";
        }
        cout << '\n';
    }

    return 0;
}