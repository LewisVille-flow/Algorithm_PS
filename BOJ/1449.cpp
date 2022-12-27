/*
    22:21-22:34, 22:47-23:24, 50m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
vector<int> pipe_funked;

void Taping_new(){
    int min_tape_num = 1;
    int covered = pipe_funked[0];
    for(int i=1; i<pipe_funked.size(); i++){
        if(covered + L-1 < pipe_funked[i]){
            min_tape_num += 1;
            covered = pipe_funked[i];
        }
    }
    cout << min_tape_num;
}

// erase 단계에서 오류가 나는 것 같음.
/*
void Taping(){
    int cur_pos, min_tape_num=0;
    while(pipe_funked.size() != 0){
        cur_pos = pipe_funked.front();

        for(int i=1; i<pipe_funked.size(); i++){
            if(cur_pos + (L-1) >= pipe_funked[i])
                pipe_funked.erase(pipe_funked.begin()+i);
        }
        pipe_funked.erase(pipe_funked.begin());

        min_tape_num += 1;
    }
    cout << min_tape_num;
}
*/

void Solve(){
    int _in;
    cin >> N >> L;
    for(int i=0; i<N; i++){
        cin >> _in;
        pipe_funked.push_back(_in);
    }
    sort(pipe_funked.begin(), pipe_funked.end());

    Taping_new();
}

int main(){
    Solve();
    return 0;
}
