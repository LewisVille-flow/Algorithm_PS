/*
    idea: Brute force with tree
        1. 입력된 자연수를 이미 visit 했다고 기록
        2. i=0부터 idx 늘려가면서 나오는 수 visit 기록
        3. 최종적으로 visit 안 한 부분 맨 밑에꺼 출력 

        debug: 부분 수열의 합이므로 여러 수가 합쳐질 수 있음에 주의
        hint: 해당 idx input으로부터 다음 수를 넣고/안넣고의 선택지가 idx=N-1 까지 존재함.
            -> backtracking 전수 조사 필요함. tree!
        
        debug 2: tree 의 해당 높이에서 해당 수를 포함/포함X 를 판단 시 단순히 visited를 기준으로 한다면
                특정 수를 건너뛰게 되는 경우가 생긴다는 것에 주의!
                -> 2^20 만큼의 경우의 수가 생기므로 최대 1초가 조금 넘을 것.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int* input;
// visited will indicate possible subsequnce number
bool visited[2000001] = {false,};

// 탈출조건: cnt == N
void Subsequence(int cnt, int value){
    //cout << value << '\n';
    if(cnt == N)
        return;

    int idx = cnt;
    /*
    if(!visited[value+input[idx]]){
        visited[value+input[idx]] = true;
        Subsequence(cnt+1, value+input[idx]);
    }
    */
    visited[value+input[idx]] = true;
    Subsequence(cnt+1, value+input[idx]);

    Subsequence(cnt+1, value);

    return;
}

int main(){
    // 1. init
    cin >> N;
    input = new int[N];
    //visited = new bool[N];      memset(visited, false, sizeof(bool)*N);
    
    for(int in=0; in<N; in++)
        cin >> input[in];

    // 2. function
    Subsequence(0, 0);

    // 3. out
    int result = 2000000;
    for(int out=1; out<2000001; out++){
        if(!visited[out]){
            result = out;
            break;
        }
    }
    cout << result << '\n';

    return 0;
}