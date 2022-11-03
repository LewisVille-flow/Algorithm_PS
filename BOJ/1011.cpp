/*
    14:30~14:40, 15:30~16:41 80m
    왜 수학문제지...? 허허
*/
#include <iostream>
using namespace std;

int T;

int Solver(){
    int start_x, start_y,  K = 0;
    cin >> start_x >> start_y;

    while(start_x < start_y){
        start_x += ++K;
        start_y -= K;
    }
    return (start_x >= start_y + K) ? 2*K -1 : 2*K;
}

int main(){
    cin >> T;
    for(int i=0; i<T; i++)
        cout << Solver() << '\n';
    
    return 0;
}