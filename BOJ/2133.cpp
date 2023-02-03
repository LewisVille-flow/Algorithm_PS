/*
    22:49-
    10분 보고 아이디어 안 떠올라서 답지 참고
    N 1 2 3 4 
    d 0 3 0
    이상한 점화식 문제. 쓰레기문제다. 
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[31] = {0};

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] * 2;
    }

    cout << dp[n];
    return 0;
}