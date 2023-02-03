/*
    11:07-11:58, 50m
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string N, result="";
int K, answer=0;
vector<int> element(3, 0);

void Permutation(){
    if(result.length() > 0 && stoi(N) >= stoi(result))
        answer = max(answer, stoi(result));
    if(result.length() == N.length())
        return;

    for(int i=0; i<K; i++){
        result += (to_string(element[i]));
        Permutation();
        result.pop_back();
    }
}

void Solve(){
    cin >> N >> K;

    for(int k=0; k<K; k++)
        cin >> element[k];

    Permutation();

    cout << answer;
}

int main(){
    Solve();
    return 0;
}