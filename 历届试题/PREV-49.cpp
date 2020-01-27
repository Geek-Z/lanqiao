#include <bits/stdc++.h>
#define MAXN 100000 + 5
using namespace std;
vector<int> G[MAXN];        // 邻接表 
int F[MAXN];                // 并查集数组
bool vis[MAXN];             // DFS中防止一个顶点被遍历两次
bool flag = false;          // 终止DFS的标记
vector<int> ans;
int ufind(int x){return x == F[x] ? x : F[x] = ufind(F[x]);}
void dfs(int cur, int e)
{
    
    if(flag) return;        // 当已经找到终点了, 则终止所有dfs
    
    ans.push_back(cur);
    vis[cur] = true;
    
    if(cur == e)
    {
        flag = true;
        return;
    }
    for(int i = 0;  i < G[cur].size(); ++i)
        if(!vis[G[cur][i]]) dfs(G[cur][i], e);

    // 找到元素了, 则当前dfs路径当中不发生回溯      
    if(!flag)
    {
        vis[cur] = false;
        ans.pop_back();
    }
}
int main()
{
#ifdef LOCAL
    freopen("PREV-49.in", "r", stdin);
#endif
    int n, u, v, b, e;
    cin >> n;
    //初始化并查集
    for(int i = 1; i <= n; ++i) F[i] = i;
    
    // 构建并查集 和 邻接表
    for(int i = 1; i <= n; ++i)
    {
        cin >> u >> v;
        int fu = ufind(u), fv = ufind(v);
        if(fu != fv) F[fu] = fv;                
        else 
        {
            b = u, e = v;                    // 找到环的起点和终点
            continue;
        }
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 开始dfs寻找答案
    dfs(b, e);
    sort(ans.begin(), ans.end());
    bool first = true;
    for(int i = 0; i < ans.size(); ++i)
        cout << (first ? "" : " ") << ans[i], first = false;
    cout << endl;
    return 0;
}