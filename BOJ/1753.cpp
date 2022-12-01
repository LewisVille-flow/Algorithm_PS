/*
    11:05~12:10, 13:10~13:20, 14:00~14:10, 15:00~15:10
    95m
    반례
    4 3
    1
    1 2 10
    2 3 10
    3 4 10
    답 
    0
    10
    20
    30

    벡터 선언에 주의할 것
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int VALUE_MAX = 98765432;

vector<int> FindShoretestDistUsingDijkstra(vector<vector<pair<int, int>>> &map, int startNode, int nodeNum){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> weightVec(nodeNum+1, VALUE_MAX);

    //int curWeight, curNode, orgDistValue, newDistValue, nextWeight, nextNode;
    
    weightVec[startNode] = 0;
    pq.push(make_pair(0, startNode));

    while(!pq.empty()){
        int curWeight = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(unsigned int i=0; i<map[curNode].size(); i++){
            int nextWeight = map[curNode][i].first;
            int nextNode = map[curNode][i].second;

            int orgDistValue = weightVec[nextNode];
            int newDistValue = curWeight + nextWeight;

            if(newDistValue < orgDistValue){
                weightVec[nextNode] = newDistValue;
                pq.push(make_pair(newDistValue, nextNode));
            }
        }
    }

    return weightVec;
}

void PrintWeight(vector<int> &vec, int num){
    for(unsigned int i=1; i<=num; i++){
        if(vec[i] == VALUE_MAX)
            cout << "INF" << '\n';
        else
            cout << vec[i] << '\n';
    }
}

void Do(){
    int V, E, startNode;
    cin >> V >> E >> startNode;

    vector<vector<pair<int, int>>> inputMap(V+1, vector<pair<int,int>>(E, {0,0}));

    for(int i=0; i<E; i++){
        int s, e, w;
        cin >> s >> e >> w;

        inputMap[s].push_back(make_pair(w, e));
    }
    
    vector<int> weightVec = FindShoretestDistUsingDijkstra(inputMap, startNode, V);

    PrintWeight(weightVec, V);

    return;
}


int main(){
    Do();
    return 0;
}