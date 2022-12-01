/*
    15:27~15:55 30m
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_VALUE = 987654321;

vector<int> FindShortestWageUsingDijkstra(vector<vector<pair<int, int>>> &map, int vertexNum, int startNode, int endNode){
    vector<int> DistVector(vertexNum+1, MAX_VALUE);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    DistVector[startNode] = 0;
    pq.push(make_pair(0, startNode));

    while(!pq.empty()){
        int curWeight = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(curNode == endNode)
            break;

        for(unsigned int i=0; i<map[curNode].size(); i++){
            int nextWeight = map[curNode][i].first;
            int nextNode = map[curNode][i].second;
            int newWeight = curWeight + nextWeight;

            if(DistVector[nextNode] > newWeight){
                DistVector[nextNode] = newWeight;
                pq.push(make_pair(newWeight, nextNode));
            }
        }
    }

    return DistVector;
}

void PrintAnswer(vector<int> &map, int end){
    cout << map[end];
    return;
}

void Do(){
    int N, M, startNode, endNode;
    cin >> N >> M;

    vector<vector<pair<int, int>>> map(N+1);
    for(int i=0; i<M; i++){
        int s, e, w;
        cin >> s >> e >> w;
        map[s].push_back(make_pair(w, e));
    }
    cin >> startNode >> endNode;

    vector<int> DistVector = FindShortestWageUsingDijkstra(map, N, startNode, endNode);

    PrintAnswer(DistVector, endNode);
    return;
}

int main(){
    Do();

    return 0;
}