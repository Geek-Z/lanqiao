#include <bits/stdc++.h>
using namespace std;
int mp[12][12];
set<pair<int, int> > cant;
int ans = 0;
void initCant(int x, int y)
{
    x -=1, y-=1;
    int begx = x - 1, begy = y - 1;
    for(int i = begx; i != begx + 3; ++i)
        for(int j = begy; j != begy + 3; ++j)
            cant.insert(make_pair(i, j));
    cant.insert(make_pair(x, y));
}

bool can(int x, int y, int n)
{
    //上面
    for(int i = x; i >= 0; --i)
        if(mp[i][y] == 1) return false;
    
    // 下面
    for(int i = x; i < n; ++i)
        if(mp[i][y] == 1) return false;
    
    // 左边
    for(int i = y; i >= 0; --i)
        if(mp[x][i] == 1) return false;
    
    // 右边
    for(int i = y; i < n; ++i)
        if(mp[x][i] == 1) return false;

    // 左上
    for(int i = x, j = y; i >= 0 && j >= 0; --i, --j)
        if(mp[i][j] == 1) return false;

    // 右上 
    for(int i = x, j = y; i >=0 && j < n; --i, ++j)
        if(mp[i][j] == 1) return false;
    
    // 左下
    for(int i = x, j = y; i < n && j >=0; ++i, --j)
        if(mp[i][j] == 1) return false;
    
    // 右下
    for(int i = x, j = y; i < n &&  j < n; ++i, ++j)
        if(mp[i][j] == 1) return false;
    return true;
}

void solve(int n, int line)
{
    if(line >= n)
    {
        ans += 1;
        return;
    }
    else
        for(int i = 0; i < n ; ++i)
        {
            if(can(line, i, n) && cant.count({line, i}) == 0)
            {
                mp[line][i] = 1;
                solve(n, line + 1);
                mp[line][i] = 0;
            }
        }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, x, y; cin >> n >> x >> y;
    initCant(x, y);
    solve(n, 0);
    cout << ans << endl;
    return 0;
}