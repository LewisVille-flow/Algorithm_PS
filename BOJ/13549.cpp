/*
    18:30 ~ 18:45, 20:28 ~ 21:10 45m

    반례 0 27 답 3,
    반례 1 2 답 0. 우선순위 큐를 이용해볼까요?/
    우선순위 큐의 pair는 앞의 값을 기준으로 정렬. + 오름차순 -> greater<자료형> 필요
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

class Solver{
    private:
        const static int _MAX = 100000;
        int N, K, answer = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Queue;
        bool visited[_MAX+1];

    public:
        Solver(){}
        void Init();
        void Solve();
        void Move(int, int);
        void Print();

        ~Solver(){}
};

void Solver::Init(){
    cin >> N >> K;

    memset(visited, false, sizeof(bool)*(_MAX +1));
    visited[N] = true;
    Queue.push(make_pair(0, N));

    return;
}

void Solver::Move(int cnt, int cur_node){
    if(cur_node*2 <= _MAX && !visited[cur_node*2]){
        visited[cur_node*2] = true;
        Queue.push(make_pair(cnt, cur_node*2));
    }
    if(cur_node + 1 <= _MAX && !visited[cur_node + 1]){
        visited[cur_node + 1] = true;
        Queue.push(make_pair(cnt +1, cur_node+1));
    } 
    if(cur_node - 1 >= 0 && !visited[cur_node - 1]){
        visited[cur_node - 1] = true;
        Queue.push(make_pair(cnt+1, cur_node-1));
    }
    return;
}

void Solver::Solve(){
    int cur_node, cnt;

    while(!Queue.empty()){
        cnt = Queue.top().first;
        cur_node = Queue.top().second;
        
        Queue.pop();
        //cout << "now: (" << cur_node << ", " << cnt << ")\n";
        
        if(cur_node == K){
            answer = cnt;
            break;
        }    

        Solver::Move(cnt, cur_node);
    }
    return;
}

void Solver::Print(){
    cout << answer;
    return;
}

int main(){
    Solver solve;
    
    solve.Init();
    solve.Solve();
    solve.Print();

    return 0;
}