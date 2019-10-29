#include <bits/stdc++.h>
using namespace std;
int mp[201][201];
int dp[201][201];

int min3(int a, int b, int c)
{
    return min(a, min(b, c));    
}

int getMaxSquare(int dp[][201], int R, int C)
{
    int maxLen = 0; 
    for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j)
    {
        if(dp[i][j] == 1)
        {
            dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen * maxLen;
}

void debug(int dp[][201], int R, int C)
{
    for(int i = 1; i <= R; ++i)
    {
        for(int j = 1; j <= C; ++j)
        {
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("ALGO-112.in", "r", stdin);
#endif
    memset(dp, 0, sizeof(dp));
    int R, C;
    cin >> R >> C;
    for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j)
    {
        cin >> mp[i][j];
        dp[i][j] = mp[i][j];
    }
    int ans1 = getMaxSquare(dp, R, C);
    memset(dp, 0, sizeof(dp));

    // 将 01 转换
    for(int i = 1; i <= R; ++i)
    for(int j = 1; j <= C; ++j)
        dp[i][j] = mp[i][j] ^ 1;
    int ans2 = getMaxSquare(dp, R, C);

    // 比较2个最大的结果
    cout << max(ans1, ans2) << endl;
    return 0;
}