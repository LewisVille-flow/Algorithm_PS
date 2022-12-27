/*
    20:46~21:02 16m
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int N, M, _tmp;
    vector<int> input;

    cin >> N >> M;
    for(int p=0; p<N; p++){
        cin >> _tmp;
        input.push_back(_tmp);
    }

    int _max = -1;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                int sum = input[i] + input[j] + input[k];
                if(sum <= M && sum > _max)
                    _max = sum;
            }
        }
    }
    cout << _max;
    return 0;
}