/*
    22:10-22:20, 10m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 1000;
int N;
vector<int> time_each;

void Total_Time(){
    int for_calculate[N_MAX];
    int ttime;

    for_calculate[0] = time_each[0];
    ttime = for_calculate[0];
    for(int i=1; i<N; i++){
        for_calculate[i] = for_calculate[i-1] + time_each[i];
        ttime += for_calculate[i];
    }

    cout << ttime;
}

void Solve(){
    int _in;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> _in;
        time_each.push_back(_in);
    }
    sort(time_each.begin(), time_each.end());

    Total_Time();
}

int main(){
    Solve();
    return 0;
}