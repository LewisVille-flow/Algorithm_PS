/*
    21:09~21:45 36m
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//void Solve(vector<int> &input, bool *visited, int start, int size){
void Solve(int *input, bool *visited, int start, int size){

    int cnt = 0;

    queue<pair<int, int>> q;

    q.push(make_pair(input[start], start));

    while(!q.empty()){
        int cur_value = q.front().first;
        int cur_pos = q.front().second;
        q.pop();

        // right side
        int next_pos = cur_pos + cur_value;
        if(next_pos <= size && !visited[next_pos]){
            visited[next_pos] = true;
            q.push(make_pair(input[next_pos], next_pos));
            cnt ++;
            //cout << "r, " << next_pos << " ";
        }

        // left side
        next_pos = cur_pos - cur_value;
        if(next_pos > 0 && !visited[next_pos]){
            visited[next_pos] = true;
            q.push(make_pair(input[next_pos], next_pos));
            cnt ++;
            //cout << "l, " << next_pos << " ";
        }
    }

    cout << cnt+1;

    return;
}

int main(){
    const int N_MAX = 100001;
    int N, _tmp, start;
    int input[N_MAX];
    bool visited[N_MAX];

    cin >> N;
    for(int i=0; i<N; i++){
        //cin >> _tmp;
        cin >> input[i+1];
    }
    cin >> start;

    memset(visited, false, sizeof(bool)*(N+1));

    visited[start] = true;
    Solve(input, visited, start, N);

    return 0;
}