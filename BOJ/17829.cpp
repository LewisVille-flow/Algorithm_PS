/*
    14:08~15:20
    Func, 종료조건, 2번째 큰수 리턴, 새로운 배열 생성, recursive
    call by reference 주의
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
//int input_grid[1025][1025];
vector<vector<int>> input_grid(1025);
vector<int> dfdf;


void Print(vector<vector<int>> _grid){
    cout << _grid[0][0];
    return;
}

int WhatIsSecondLargeNum(vector<vector<int>> _grid, int size, int _i, int _j){
    int answer = 0;
    int next_size = size/2;
    int i_idx = 2*_i, j_idx = 2*_j;
    vector<int> Compare;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            Compare.push_back(_grid[0+i_idx+i][0+j_idx+j]);
        }
    }

    sort(Compare.begin(), Compare.end());
    answer = Compare[2];

    return answer;
}

void Custom_Pooling(vector<vector<int>> _grid, int size){
    if(size == 1){
        Print(_grid);
        return;
    }

    int next_size = size/2;
    vector<vector<int>> next_grid(next_size);
    
    for(int i=0; i<next_size; i++){
        for(int j=0; j<next_size; j++){
            int second_num = WhatIsSecondLargeNum(_grid, size, i, j);
            next_grid[i].push_back(second_num);
        }
    }

    Custom_Pooling(next_grid, next_size);

    return;   
}

int RecursiveCustomPooling(int size, int x, int y){
    int SecondValue;
    vector<int> ToCompare;
    if(size == 2){
        ToCompare.push_back(input_grid[x][y]);
        ToCompare.push_back(input_grid[x+1][y]);
        ToCompare.push_back(input_grid[x][y+1]);
        ToCompare.push_back(input_grid[x+1][y+1]);
        
        sort(ToCompare.begin(), ToCompare.end());

        SecondValue = ToCompare[2];
        return SecondValue;
    }

    ToCompare.push_back(RecursiveCustomPooling(size/2, x, y));
    ToCompare.push_back(RecursiveCustomPooling(size/2, x+size/2, y));
    ToCompare.push_back(RecursiveCustomPooling(size/2, x, y+size/2));
    ToCompare.push_back(RecursiveCustomPooling(size/2, x+size/2, y+size/2));
    
    sort(ToCompare.begin(), ToCompare.end());
    SecondValue = ToCompare[2];
    return SecondValue;
}

void Solve(){
    //Custom_Pooling(input_grid, N);
    int answer = RecursiveCustomPooling(N, 0, 0);
    cout << answer;
    
    return;
}

void Init(){
    int tmp;
    input_grid.clear();

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> tmp;
            input_grid[i].push_back(tmp);
        }
    }

    return;
}

void Do(){
    Init();
    Solve();
    return;
}


int main(){
    Do();
    return 0;
}

