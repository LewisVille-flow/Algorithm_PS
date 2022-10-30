/*
    21:05~22:16
    idea: DFS + 3차원 visit 행렬 체크로 중복 제거 + 중복 효율적 제거를 위해 sort 알고리즘 추가
    -> 통과는 했으나 형편없는 시간과 메모리가 발생

    수학적 접근
    X = X+X, Y = Y-X 에서 돌의 전체 개수는 줄어들지 않음을 확인,
    나머지 돌의 개수는 sum - X - Y로 계산 할 수 있으므로 visit은 (X, Y) 로 확인하면 된다.
    + DFS 메모리 사용량을 줄이기 위한 BFS 설계
    -> 메모리는 비슷하게 먹지만, 시간을 1/10으로 줄임(150ms -> 12ms)
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int A, B, C;
bool visited_dfs[501][501][501];
// 최대 500+500-1 = 999 까지 도달 가능
//bool** visited_bfs;
bool visited_bfs[1000][1000];
bool answer = false;
int sum;
queue<pair<int, int>> Queue;



void Search_BFS(){
    int a, b, c;

    while(!Queue.empty()){
        int tmp[3] = {0};
        tmp[0] = Queue.front().first;
        tmp[1] = Queue.front().second;
        tmp[2] = sum - tmp[0] - tmp[1];

        if(tmp[0] == tmp[1] && tmp[1] == tmp[2]){
            answer = true;
            break;
        }
        Queue.pop();

        for(int i=0; i<3; i++){
            int j = (i+1)%3;

            a = min(tmp[i], tmp[j]);
            b = max(tmp[i], tmp[j]);

            b -= a;
            a += a;
            if(b <= 0)  continue;
     
            if(!visited_bfs[a][b]){
                visited_bfs[a][b] = true; visited_bfs[b][a] = true;
                Queue.push(make_pair(a, b));
                //cout << "(" << a << ", " << b << ")\n";
            }
        }
    }
    return;
}

void Search_DFS(vector<int> v_in){
    //cout << "(" << v_in[0] << ", " << v_in[1] << ", " << v_in[2] << ")\n";
    
    // 1. end condition
    if(v_in[0] == v_in[1] && v_in[1] == v_in[2]){
        answer = true;
        //cout << "found" << '\n';
        return;
    }

    for(int i=0; i<3; i++){
        int j = (i+1)%3;
        int smaller = min(v_in[i], v_in[j]);
        int bigger = max(v_in[i], v_in[j]);

        //cout << bigger << ", " << smaller << '\n';
        bigger = bigger - smaller;
        smaller = 2*smaller;
        
        if(bigger <= 0) continue;

        vector<int> v;
        v.push_back(smaller);   v.push_back(bigger);   v.push_back(sum - smaller - bigger);
        sort(v.begin(), v.end());

        if(!visited_dfs[v[0]][v[1]][v[2]]){
            visited_dfs[v[0]][v[1]][v[2]] = true;
            Search_DFS(v);
        } 
    }
    //cout << "return" << '\n';
    return;
}
int main(){
    // 1. init
    cin >> A >> B >> C;
    sum = A+B+C;
    //visited_bfs = new bool*[sum];
    for(int i=0; i<sum; i++){
        //visited_bfs[i] = new bool[sum];
        memset(visited_bfs[i], false, sizeof(bool)*sum);
    }
    
    // 2. function

    /* 
    // for DFS
    vector<int> input;
    input.push_back(A); input.push_back(B); input.push_back(C);
    sort(input.begin(), input.end());
    
    
    for(int i=0; i<500; i++){
        for(int j=0; j<500; j++){
            for(int k=0; k<500; k++)
                visited_dfs[i][j][k] = false;
        }
    }

    //visited_dfs[input[0]][input[1]][input[2]] = true;
    //Search_DFS(input);
    */
    // for BFS
    visited_bfs[A][B] = true;   visited_bfs[B][A] = true;
    Queue.push(make_pair(A, B));

    Search_BFS();


    // 3. out
    cout << answer << '\n';

    return 0;
}