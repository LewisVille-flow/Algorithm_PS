/*
    16:57-17:55, 18:10-18:15, 65m

    //dp array의 i = 만들게되는 수의 범위
    //dp array의 j = 고려하는 수.
    최종적으로 뒤집어진 input에 대해 첫 수를 빼거나 더해서 0인경우 수  == answer  .. 해당 방식은 첫 번째 수에 대한 예외가 발생해 처리하기 번거로움

    // -> 따라서, 어차피 answer = dp[0][N-2] 할 바에, dp[N-1][N-2] 하는게 낫겠다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input;
long long dp_array[21][101];


void DP_Solve(){
    long long answer = 0;
    int _first = input[0];
    
    fill(&dp_array[0][0], &dp_array[20][101], 0);

    dp_array[input[0]][0] = 1;              // 첫 번째 input은 무조건 + 한다

    for(int j=1; j<N-1; j++){               // j == 주어진 수
        for(int i=0; i<21; i++){            // i == +, - 연산으로 만들 수 있는 수
            
            if(dp_array[i][j-1] != 0){
                if(i - input[j] >= 0)
                    dp_array[i - input[j]][j] += dp_array[i][j-1];
                if(i + input[j] <= 20)
                    dp_array[i + input[j]][j] += dp_array[i][j-1];
            }
        }
    }
    answer = dp_array[input[N-1]][N-2];
    cout << answer;
}

void Solve(){
    int _in;

    cin >> N;
    for(int n=0; n<N; n++){
        cin >> _in;
        input.push_back(_in);
    }    

    DP_Solve();
}

int main(){
    Solve();
    return 0;
}