/*
    15:57~16:20
    주어진 사이즈 내에 모두 같은 원소인지 재귀적으로 확인
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int inputGrid[65][65];

bool CheckIfAllNumSame(int size, int x, int y){
    int startNum = inputGrid[x][y];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(inputGrid[x+i][y+j] != startNum)
                return false;
        }
    }
    return true;
}


void RecursiveQuadTree(int size, int x, int y){
    int zippedNum;
    //cout << "size, x, y: (" << size << ", " << x << ", " << y << ")\n";
    //check if all num is same
    if(CheckIfAllNumSame(size, x, y)){
        // if yes
        zippedNum = inputGrid[x][y];
        cout << zippedNum;
        return;
    }

    // if no
    cout << "(";
    RecursiveQuadTree(size/2, x, y);
    RecursiveQuadTree(size/2, x, y+size/2);
    RecursiveQuadTree(size/2, x+size/2, y);
    RecursiveQuadTree(size/2, x+size/2, y+size/2);
    cout << ")";

    return;
}

void Init(){
    string _in;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> _in;
        for(int j=0; j<N; j++)
            inputGrid[i][j] = _in[j] - '0';
    }
    return;
}

void Do(){
    Init();
    RecursiveQuadTree(N, 0, 0);
    return;
}

int main(){
    Do();
    return 0;
}