/*
    11:49-12:12, 25m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, x, y;
    int x_middle, y_middle;
    long long answer=0;
    cin >> N;
    vector<int> x_vector;
    vector<int> y_vector;

    for(int i=0; i<N; i++){
        cin >> x >> y;
        x_vector.push_back(x);
        y_vector.push_back(y);
    }
    sort(x_vector.begin(), x_vector.end());
    sort(y_vector.begin(), y_vector.end());

    x_middle = x_vector[(N-1)/2];
    y_middle = y_vector[(N-1)/2];

    for(int i=0; i<N; i++){
        answer += abs(x_middle - x_vector[i]);
        answer += abs(y_middle - y_vector[i]);
    }
    cout << answer;

    return 0;
}