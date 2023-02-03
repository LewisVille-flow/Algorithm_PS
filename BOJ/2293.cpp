/*
    13:13- 답 참고함 14:05
    - 순서만 다른 경우는 같은 것이다.
    비슷한 유형을 정리할 필요가 있다. 동전 2, 프로그래머스 어제 푼 것(11/20)

      1 2 2 3 4  2 1 3
      1 2 2 3 4 5 5 6 6 7

    1 1 1
    2 1

    1 1 1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1 2
    1 1 1 1 1 1 2 2
    1 1 1 1 2 2 2
    1 1 2 2 2 2
    2 2 2 2 2
    1 1 1 1 1 5
    1 1 1 2 5
    1 2 2 5
    5 5


    1 1 1 1
    1 1 2
    2 2

    1 1 1 1 1
    1 1 1 2
    1 2 2
    5

    1 1 1 1 1 1     5
    1 1 1 1 2       5
    1 1 2 2         5
    2 2 2           4
    1 5             5

    0 1 2 3 4 5 6 7 8 9 10
    1 1 1 1 1 1 1 1 1 1 1 
    2 1 2 2 3 3 4 4 5 5 6
    5 1 2 2 3 4 5 6 7 8 10

    1 1 1 1 1 1 1 1 1 1 1
    1 1 2 2 3 3 4 4 5 5 6
    1 1 2 2 3 4 5 6 7 8 10
    굳이 2차배열까지 안 써도 된다. ㅠㅠㅠㅠ
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 101;
const int K_MAX = 10001;
int N, K;
int coin[N_MAX];
int dp_array[K_MAX];

int Solve(){
    cin >> N >> K;
    fill(dp_array, dp_array+K+1, 0);

    for(int n=0; n<N; n++)
        cin >> coin[n];

    dp_array[0] = 1;
    for(int i=0; i<N; i++){                //coin[i]에 대해서
        for(int j=coin[i]; j<=K; j++)
            dp_array[j] += dp_array[j-coin[i]];
    }
    return  dp_array[K];    
}

int main(){
    int answer = Solve();
    cout << answer;
    return 0;
}
