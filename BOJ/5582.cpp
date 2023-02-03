/*
    23:17-
    - 연속한 문자열 중 공통인 것의 최대 길이
    비교 대상은 두 문자열이므로 2차원 dp
    LCS와 같은 접근을 쓰면 될 것 같다. 대신, 연속해야하므로 같지 않은 경우는 0이다.
    따라서 dp 배열의 마지막 행의 최대 값을 리턴해야겠다.--> 최댓값이 중간에 잇을 거라는 생각을 못했다.

    dp[i][j] = dp[i-1][j-1] + 1, if char is same
                                if not, dp = 0;
                                --- 틀렸다고 생각했는데, 같지 않은 경우 result가 갱신되지 않는 경우(길이==1)가 생겼다.
                                초기값을 0으로 하면 된다.
*/
#include <iostream>
#include <cstring>

using namespace std;

string inputA, inputB;
int dp_array[4001][4001];

int Solve(){
    int result = -1;
    cin >> inputA >> inputB;
    fill(&dp_array[0][0], &dp_array[inputA.size()][inputB.size()+1], 0);

    for(int i=1; i<=inputA.size(); i++){
        for(int j=1; j<=inputB.size(); j++){
            if(inputA[i-1] == inputB[j-1]){
                dp_array[i][j] = dp_array[i-1][j-1] + 1;
                result = max(result, dp_array[i][j]);
            }
                
            //cout << dp_array[i][j] << " ";
        }
        //cout << '\n';
    }
    //for(int i=0; i<=inputB.size(); i++)
    //    result = max(result, dp_array[inputA.size()][i]);
    return result;
}

int main(){
    int answer = Solve();
    cout << answer;
    return 0;
}