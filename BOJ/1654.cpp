/*
    19:29-19:57, 30m
    - 어떠한 '수'를 찾는 데 이분 탐색을 쓴 것이고,
    - '찾는' 조건이 랜선 개수 -> 나눗셈에서의 몫의 합이 되는 것이며,
    - '최대한 긴' 답을 찾기 위해 서치를 계속 하되, 안 될 경우를 대비한 저장이 필요함.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N_MAX = 1000001;
int K, N;
int input[N_MAX];

void Solve(){
    cin >> K >> N;
    for(int i=0; i<K; i++)
        cin >> input[i];
    sort(input, input+(K));

    long long left=1, right=input[K-1], mid;
    int count = 0;
    long long answer = -1;

    while(left<=right){
        count = 0;
        mid = (right+left)/2;

        for(int i=0; i<K; i++)
            count += input[i]/mid;

        if(count >= N){
            left = mid + 1;
            answer = max(answer, mid);
        }
        
        else
            right = mid - 1;
    }
    cout << answer;
}

int main(){
    Solve();
    return 0;
}