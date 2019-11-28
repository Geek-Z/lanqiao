#include <bits/stdc++.h>
using namespace std;
int uf[10001];
int c[10001];
struct Edge{
    int from, to, dist;
    Edge(int f, int t, int d) : from(f), to(t), dist(d){}
    bool operator < (const Edge &rhs) const{
        return this->dist < rhs.dist;
    }
};
vector<Edge> edges;
int ufind(int x) {return uf[x] == x ? x : uf[x] = ufind(uf[x]);}
int main()
{
#ifdef LOCAL
    freopen("ALGO-6.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    int N, P, u, v, d, ans = 0, minNode = INT_MAX;
    cin >> N >> P;
    for(int i = 1; i <= N; ++i)
        cin >> c[i], minNode = min(minNode, c[i]);
    for(int i = 0; i < P; ++i) {
        cin >> u >> v >> d;
        d = c[u] + c[v] + 2 * d;
        edges.push_back(Edge(u, v, d));
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= N; ++i) uf[i] = i;
    for(int i = 0; i != edges.size(); ++i){
        u = edges[i].from, v = edges[i].to;
        int fu = ufind(u), fv = ufind(v);
        if(fu != fv){
            ans += edges[i].dist;
            uf[fu] = fv;
        }
    }
    cout << (ans + minNode) << endl; 
    return 0;
}
