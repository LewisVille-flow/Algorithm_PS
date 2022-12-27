/*
    13:44-14:30, 15:10-15:32 75m
*/
#include <iostream>
#include <stack>

using namespace std;

const int N_MAX = 1000001;
int N, answer=0;
stack<int> skyline_y;


void Solve(int cur_height){
    while(!skyline_y.empty() && skyline_y.top() > cur_height){
        answer++;
        skyline_y.pop();
    }
    if(!skyline_y.empty() && skyline_y.top() == cur_height){}
    else
        skyline_y.push(cur_height);

    return;
}

int main(){
    //
    int _inx, _iny;
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> _inx >> _iny;
        Solve(_iny);
    }

    while(!skyline_y.empty()){
        if(skyline_y.top() > 0)
            answer++;
        skyline_y.pop();
    }

    cout << answer;

    return 0;
}