#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(int n)
{   if(n < 0) return;
    if(n == 0)
    {
        ans += 1;
    }
    else
    {
        dfs(n-1);
        dfs(n-2);
    }
}
int main()
{
    int n; cin >> n;
    dfs(n);
    cout << ans << endl;
    return 0;
}