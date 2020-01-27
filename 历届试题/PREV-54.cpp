#include <bits/stdc++.h>
int uarr[1001 * 1001];
int ufind(int x) { return uarr[x] == x ? x : uarr[x] = ufind(uarr[x]);}
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("PREV-54.in", "r", stdin);
#endif
    int m, n, k; cin >> m >> n >> k;
    // 初始化并查集
    int cnt = m * n;
    for(int i = 1; i <= cnt; ++i) uarr[i] = i; 
    while(k--)
    {
        int u, v; cin >> u >> v;
        int fu = ufind(u), fv = ufind(v);
        if(fu != fv)
            uarr[fu] = fv;
    }
    int ans = 0;
    for(int i = 1; i <= cnt; ++i)
    {
        int parent = ufind(i);
        if(i == parent) ans += 1;
    }
    cout << ans << endl;
    return 0;
}