/*
    11:32~11:47
    단순히 다음 값만 보지말고, 건너서도 더 큰 값이 있는지 확인해야함.
*/
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N, tmp;
    vector<int> input;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    //
    int leftMax = input[0];
    int rightMax = input[input.size()-1];
    int leftCnt = 1, rightCnt = 1;

    for(unsigned int i=1; i<input.size(); i++){
        if(input[i] > leftMax){
            leftCnt ++;
            leftMax = input[i];
        }
        if(input[input.size()-1-i] > rightMax){
            rightCnt ++;
            rightMax = input[input.size()-1-i];
        }
    }

    cout << leftCnt << '\n' << rightCnt;

    return 0;
}