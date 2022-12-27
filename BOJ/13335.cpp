/*
    17:37-18:08, 20:35-21:03, 60m, 너무 어렵게 풀었다.
반례
5 5 18
7 1 9 3 8
#answer = 13
*/
#include <iostream>
#include <queue>

using namespace std;

int N, L, W;
queue<int> truck_weight;
vector<pair<int, int>> on_the_bridge;

void Solve(){
    int cur_weight, time = 0;               // for total weight on bridge, time for answer
    int _weight = truck_weight.front();
    truck_weight.pop();

    cur_weight = _weight;                   // first weight on the bridge
    on_the_bridge.push_back(make_pair(_weight, 0));

    while(!on_the_bridge.empty()){
        time += 1;                          // count time

        int size = on_the_bridge.size();
        for(int i=0; i<size; i++)
            on_the_bridge[i].second += 1;   // increase time til to meet length 
        
        if(on_the_bridge.front().second > L){// truck out //--- 이게 지워지면서 다음 거 second 값이 ++이 되지 않았다.
            cur_weight -= on_the_bridge.front().first;
            on_the_bridge.erase(on_the_bridge.begin());
        } 

        int next_weight;                    // for the next truck
        if(!truck_weight.empty()){
            next_weight = truck_weight.front();
            if(cur_weight + next_weight <= W){
                cur_weight += next_weight;  // 
                on_the_bridge.push_back(make_pair(next_weight, 1));
                truck_weight.pop();
            }
        }
        else{}
    }

    cout << time;
}

void Init(){
    int _in;
    cin >> N >> L >> W;

    for(int i=0; i<N; i++){
        cin >> _in;
        truck_weight.push(_in);
    }
}

int main(){
    Init();
    Solve();
    return 0;
}