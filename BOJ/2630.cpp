#include <iostream>

using namespace std;

int N;
int input[128][128];
int blue_num = 0, white_num = 0;

void Init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        for (int j = 0; j < N; j++)
            cin >> input[i][j];
    }
    return;
}

void Solve(int x, int y, int size){
    int _color = input[x][y];
    for(int i=x; i<x+size; i++){
        for (int j=y; j<y+size; j++){
            int _temp = input[i][j];
            if(_color != _temp){
                Solve(x, y, size/2);
                Solve(x, y+size/2, size/2);
                Solve(x+size/2, y, size/2);
                Solve(x+size/2, y+size/2, size/2);
                return;
            }
        }
    }
    if(_color)  blue_num += 1;
    else        white_num += 1;
    
    return;
}

void Print(){
    cout << white_num << '\n';
    cout << blue_num << '\n';
    return;
}

int main(){

    Init();
    Solve(0, 0, N);
    Print();

    return 0;
}