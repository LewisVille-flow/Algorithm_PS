#include <iostream>

using namespace std;

int main(){
    const int N_MAX = 10000;
    int N, M;
    int input[N_MAX];
    int start=0, end=0, answer=0, sum=0;
    cin >> N >> M;

    for(int i=0; i<N; i++)
        cin >> input[i];

    while(start<N){
        if(sum < M)
            sum += input[end++];
        if(sum > M)
            sum -= input[start++];
        if(sum == M){
            answer += 1;
            sum = 0;
            start++;
            end = start;
        }
        
    }
    cout << answer;

    return 0;
}