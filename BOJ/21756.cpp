/*
    10:30~11:20 50m 구현에서 어려움을 느낀다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Eraser(vector<int> &input, int size){
    while(input.size()> 1){
        

        vector<int> tmp;
        int iterNum = input.size();

        for(int i=1; i<=iterNum; i++){
            if(i%2 == 0)
                tmp.push_back(input[i-1]);
        }

        input.clear();
        for(unsigned int i=0; i<tmp.size(); i++){
            input.push_back(tmp[i]);
        }
    }
    cout << input[0];
    return;
}

void Do(){
    int N, answer;
    cin >> N;

    vector<int> input(N, 0);
    
    for(int i=0; i<N; i++)
        input[i] = i+1;
    
    Eraser(input, N);

    return;
}

int main(){
    Do();
    return 0;
}