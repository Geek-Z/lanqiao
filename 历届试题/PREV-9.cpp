#include <bits/stdc++.h>
#define MAXN 10009
using namespace std;
// 邻接表的结构
struct Edge
{
    int to, len;
    Edge(int t, int l){to = t; len = l;}
};
vector<Edge> G[MAXN];
bool vis[MAXN];
int degree[MAXN];                   // 每个点的度
int n, u, v, w;
int maxDis = INT_MIN;               // 两次记录最长的路径的变量
int a;                              // 找到出发点a
void findA(int cur, int dis)
{
    vis[cur] = true;
    if(degree[cur] == 1 && dis != 0) 
    {
        if(dis > maxDis)
        {
            maxDis = dis;
            a = cur;
        }   
    }
    else
    {
        // 向邻接到的顶点进行dfs
        for(int i = 0; i < G[cur].size(); ++i)
        {
            if(!vis[G[cur][i].to])
            {
                findA(G[cur][i].to, dis + G[cur][i].len);
            }
        }
    }
    
    // 判断是否向
    vis[cur] = false;
}
int main()
{
#ifdef LOCAL
    freopen("PREV-9.in", "r", stdin);
#endif
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        cin >> u >> v >> w;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
        
        // 统计度数
        degree[u]+= 1, degree[v] += 1;
    }
    
    memset(vis, false, sizeof(vis));
    findA(1, 0);
    memset(vis, false, sizeof(vis));
    findA(a, 0);
    cout << (10 * maxDis + maxDis * (maxDis + 1) / 2) << endl;
    return 0;
}