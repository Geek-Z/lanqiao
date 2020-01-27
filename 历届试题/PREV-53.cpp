#include <bits/stdc++.h>
#define MAXN 100 + 5
using namespace std;
int G[MAXN][MAXN];          // 邻接矩阵
int room[MAXN][MAXN];       // 每个房间当中具体的人
int cnt[MAXN];              // 每个房间当中的人数
int ans = INT_MAX;
int n, m, u, v;
// id为学生编号, num为到达当前节点的时候, 房间的数量
void dfs(int id, int num)
{
    if(id == n + 1)
    {
        ans = min(num, ans);
        return;
    }

    // 减枝
    if(num >= ans) return;

    // 先前的房间不能放置
    for(int i = 0; i < num; ++i)
    {
        int len = cnt[i];   // 房间当中的人数
        int c = 0;
        // 循环房间的人 
        for(int j = 0; j < len; ++j)
        {
            // 房间的人和id学生不认识
            if(G[id][room[i][j]] == 0) c++;
        }
        // 该学生和房间当中的人均不认识
        if(c == len)
        {
            room[i][len] = id;
            cnt[i] +=1;
            dfs(id + 1, num);
            cnt[i] -=1;
            room[i][len] = 1;
        }
    }

    //开一个新的房间
    room[num][0] = id;
    cnt[num] += 1;
    dfs(id + 1, num + 1);
    cnt[num] -= 1;
    room[num][0] = 0;
}

int main()
{
#ifdef LOCAL
    freopen("PREV-53.in", "r", stdin);
#endif
    cin >> n >> m;
    memset(G, 0, sizeof(G));

    while(m--)
    {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    dfs(1, 0);
    cout << ans << endl;
    return 0;
}