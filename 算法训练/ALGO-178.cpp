#include <bits/stdc++.h>
using namespace std;
int repeat[21][21], G[21][21], njs[11], state[21], uf[21];
int ufind(int x) { return x == uf[x] ? x : uf[x] = ufind(uf[x]);}
vector<int> paths[10];
struct Edge{
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return this->w < rhs.w;
    }
}edges[21];

void dfs(int s, int d, int nc,vector<int> &nodes, int &distance, bool &find);

int main()
{
#ifdef LOCAL
    freopen("ALGO-178.in", "r", stdin);
#endif
    memset(state, 0, sizeof(state));
    memset(repeat, 0, sizeof(repeat));
    for(int i = 1; i < 21; ++i) uf[i] = i;
    for(int i = 1; i < 21; ++i)
        for(int j = 1; j < 21; ++j)
            if(i == j) G[i][j] = 0;
            else G[i][j] = INT_MAX;
    int nc, dc, nr, nj; cin >> nc >> dc >> nr;
    for(int i = 0; i <nr; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges, edges + nr);
    // 构造最小生成树
    for(int i = 0; i <nr; ++i) {
        int u = edges[i].u, v = edges[i].v;
        int fu = ufind(u), fv = ufind(v);
        if(fu != fv) {
            uf[fu] = fv;
            G[u][v] = edges[i].w;
            G[v][u] = edges[i].w;
        }
    }
    // for(int i = 1; i <= nc; ++i) {
    //     for(int j = 1; j <= nc; ++j)
    //         cout << G[i][j] << " ";
    //     cout << endl; 
    // }


    // 输入人数数据, 计算路线和金钱
    cin >> nj;
    int distance = 0;
    for(int i = 0; i < nj ; ++i) {
        cin >> njs[i];
        bool find = false;
        dfs(njs[i], dc, nc, paths[i], distance, find);
    }
    cout << "distance = " << distance << endl;
    for(int i = 0; i < nj; ++i) {
        bool first = true;
        for(int j = 0; j < paths[i].size(); ++j) {
            cout << (first ? "" : "-") << paths[i][j], first = false;
        }
        cout << endl;
    }
    return 0;
}

void dfs(int s, int d, int nc,vector<int> &nodes, int &distance, bool &find) {

    //cout << s << "--" << d << "--" << distance << endl;

    state[s] = 1;
    nodes.push_back(s);
    if(s == d)
        find = true;

    for(int i = 1; i <= nc; ++i) {
        if(G[s][i] != 0 && G[s][i] != INT_MAX && state[i] == 0) {
            bool add = false;
            if(!find && !repeat[s][i]) distance += G[s][i], repeat[s][i] = 1, add = true;
            
            if(!find) dfs(i, d, nc, nodes, distance, find);

            // 在没有找到的情况下才回溯
            if(!find && add)
                repeat[s][i] = 0, distance -= G[s][i];
        }
    } 
    if(!find) nodes.pop_back();
    state[s] = 0;
}

/**
distance = 39
6-8-1
**/