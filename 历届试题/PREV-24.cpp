#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
}points[51];                    // 先存放居民
double dist[51][26];            // 居民到邮局的距离                
int ans[26];                    // 选择的邮局
int temp[26];                   
double minDis = INT_MAX;        // 最小距离
int m, n, k, x, y;

// 计算村名和已经选择的邮局之间的最小距离
double getDis(int l)
{
    double dis = 0;
    for(int i = 1; i <= n; ++i)
    {
        // i 村民 到 选中邮局的最短距离
        double t = INT_MAX;
        for(int j = 1; j <= l; ++j)
        {
            t = min(t, dist[i][temp[j]]);
        }
        dis += t;
    }
    return dis;    
}

// cur 表示已经选择第几个数字啦
// pos 表示在邮局当中选择的数字
void Cn(int cur, int pos, double pDis)
{
    if(cur == k + 1)
    {
        
        if(pDis < minDis)
        {
            memcpy(ans, temp, 26 * sizeof(int));
            minDis = pDis;
        }
        return;
    }

    // 剪枝
    if(m - pos < k - cur) return;

    // 选择下一个数
    for(int i = pos; i <= m; ++i)
    {
        temp[cur] = i;
        double dis = getDis(cur);
        // 选择当前邮局并没有导致缩减, 则该邮局就不选择
        if(dis < pDis)
        {
            Cn(cur + 1, i + 1, dis);
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("PREV-24.in", "r", stdin);
#endif
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        for(int j = 0; j < n; ++j)
        {
            int sx = points[j].x - x;
            int sy = points[j].y - y;
            dist[j + 1][i + 1] = sqrt((sx * sx + sy * sy) * 1.0);
        }
    }
    //cout << n << m << k << endl;
    Cn(1, 1, INT_MAX);
    bool first = true;
    for(int i = 1; i <= k; ++i)
        cout << (first ? "" : " ") << ans[i], first = false;
    cout << endl;
    return 0;
}