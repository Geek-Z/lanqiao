#include <bits/stdc++.h>
#define MAXN 100 + 5
using namespace std;
int a[MAXN][MAXN];    
bool vis[MAXN][MAXN];      // 标记是否访问过了
int minAns = INT_MAX;
int Sum = 0;
// 上右下左
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
void dfs(int r, int c, int n, int m, int tsum, int k)
{
    if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c]) return;
    
    vis[r][c] = true;
    k += 1;
    tsum += a[r][c];
    if(tsum == Sum / 2){minAns = min(minAns, k); vis[r][c] = false;}
    // 减枝
    if(tsum > Sum / 2){ vis[r][c] = false; return;}
    // 剩下是tsum < Sum 的情况, 则向四个方向继续搜索
    for(int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i], nc = c + dc[i];
        dfs(nr, nc, n, m, tsum, k);
    }

    // 回溯
    vis[r][c] = false;

}

int main()
{
#ifdef LOCAL
    freopen("PREV-4.in", "r", stdin);
#endif
    memset(vis, false, sizeof(vis));
    int m, n; cin >> m >> n;
    for(int i = 0; i < n; ++i) 
    for(int j = 0; j < m; ++j)
        cin >> a[i][j], Sum += a[i][j];
    dfs(0, 0, n, m, 0, 0);
    cout << minAns << endl;
    return 0;
}