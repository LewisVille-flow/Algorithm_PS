/*
    21:35~22:05
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int N;
const int N_MAX = 2201;
int input[N_MAX][N_MAX];
int output[3];

using namespace std;

bool IfSame(int x, int y, int size){
    int first_value = input[x][y];
    int tmp;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tmp = input[x+i][y+j];
            if(tmp != first_value)
                return false;
        }
    }
    return true;
}

void Solve(int x, int y, int size){
    int first_value = input[x][y];
    
    if(IfSame(x, y, size)){
        output[first_value+1] += 1;
        return;
    }

    for(int m=0; m<3; m++){
        for(int n=0; n<3; n++)
            Solve(x+(size/3)*n, y+(size/3)*m, size/3);
    }

    return;
}

void Init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    fill(&input[0][0], &input[N+1][N+1], 0);
    fill(output, output+3, 0);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> input[i][j];
    }

    return;
}

void Print(){
    
    for(int i=0; i<3; i++)
        cout << output[i] << '\n';

    return;
}

void Do(){
    Init();
    Solve(0, 0, N);
    Print();

    return;
}

int main(){

    Do();
    
    return 0;
}