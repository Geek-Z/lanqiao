#include <bits/stdc++.h>
using namespace std;
int n;
string strs[20];
int vis[20];
int ans = 0;
void dfs(string temp)
{
    // 在剩余的字符串当中进行搜寻的
    int cnt = 0;
    int plen = temp.size();
    for(int i = 0; i < n; ++i)
    {
        if(vis[i] >= 2) continue;
        int nlen = strs[i].size();
        int len = min(plen, nlen) - 1;
        
        // 判断前是否重叠
        for(int j = 1; j <= len; ++j)
        {
            // 有重叠的部分
            if(string(temp.begin() + plen - j, temp.end()) == string(strs[i].begin(), strs[i].begin() + j))
            {
                cnt += 1;
                vis[i] += 1;
                dfs(temp + string(strs[i].begin() + j, strs[i].end()));
                vis[i] -= 1;
                break;
            }
        }
    }
    if(cnt == 0)
    {
        ans = max(ans, plen);
        //cout << temp << endl;
    }
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-18.in", "r", stdin);
#endif
    char c;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> strs[i];
    cin >> c;
    for(int i = 0; i < n; ++i) if(strs[i][0] == c)
    {
        vis[i] += 1;
        dfs(strs[i]);
        vis[i] -= 1;
    }
    cout << ans << endl;
    return 0;
}