/**
   边权为负数, 因此使用Bellman-Ford 算法
**/
#include <bits/stdc++.h>
#define N 20001
#define M 200001
using namespace std;
struct Edge{
    int from, to, dist;
}edges[M];
int m = 0;
vector<int> head[N];    // 邻接表头
int d[N];               // 经过k轮松弛得到最短路
bool inq[N];            // 表示已经在队列当中
void addEdge(int from, int to, int dist) {
    edges[m].from = from, edges[m].to = to, edges[m].dist = dist;
    head[from].push_back(m++);
}

int bellmanFord(int s, int n, int m) {
    queue<int>  Q;
    memset(inq, 0, sizeof(inq));
    for(int i = 1; i <= n; ++i) d[i] = INT_MAX;
    d[s] = 0;
    inq[s] = true;
    Q.push(s);
    
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = false;
        for(int i = 0; i < head[u].size(); ++i) {       // 循环当前顶点链接的边
            Edge& e = edges[head[u][i]];
            if(d[u] < INT_MAX && d[e.to] > d[u] + e.dist) {
                d[e.to] = d[u] + e.dist;
                if(!inq[e.to]) Q.push(e.to);
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-5.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i != m; ++i)
        cin >> u >> v >> w, addEdge(u, v, w);
        
    bellmanFord(1, n, m);
    for(int i = 2; i <= n; ++i)
        cout << d[i] << endl;
    return 0;
}