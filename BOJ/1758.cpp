/*
    15:25~15:44 19m
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve(vector<int> &tip, int N){
    sort(tip.begin(), tip.end(), greater<int>());

    long long sum_of_tip = 0, tip_of_i = 0;

    for(int i=0; i<N; i++){
        tip_of_i = tip[i] - (i);

        if(tip_of_i >= 0)
            sum_of_tip += tip_of_i;
    }

    cout << sum_of_tip;
    return;
}

int main(){
    int N;
    vector<int> tip;
    cin >> N;
    
    for(int n=0; n<N; n++){
        int _tmp;
        cin >> _tmp;
        tip.push_back(_tmp);
    }

    Solve(tip, N);
    return 0;
}