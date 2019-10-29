/**
    dp[i][j] 表示第i位, 以j结尾的数量
    则dp[i][j] = dp[i - 1][a1] + dp[i - 1][a2] + ...
    a1, a2, ... 表示和j不相邻的数
**/
#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int main()
{
    std::ios::sync_with_stdio(false);
    int K, L, ans = 0;
    cin >> K >> L;
    for(int i = 0; i < K; ++i)
        if(i != 0)
            dp[1][i] = 1;
    for(int bit = 2; bit <= L; ++bit)
    {
        for(int j = 0; j < K; ++j)
        {
            for(int next = 0; next < K; ++next)
            {
                if(abs(j - next) != 1)
                    dp[bit][j] = (dp[bit][j] + dp[bit - 1][next]) % 1000000007;
            }
        }
    }
    // 计算最终结果
    for(int i = 0; i < K; ++i)
        ans = (ans + dp[L][i]) % 1000000007;
    cout << ans << endl;
    return 0;
}