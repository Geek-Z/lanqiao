/**
    以秒为单位进行模拟。
    
    (1) 模拟每只蚂蚁移动一次
    (2) 计算新感染的蚂蚁数量
    (3) 删除掉能离开的蚂蚁
**/
#include <bits/stdc++.h>
using namespace std;
map<int, bool> status;                  // 标记每只蚂蚁是否感染
struct Ant
{
    int pos;
    int dir;
    bool sick;
}ants[55];
// 从小到大排序
bool compare(const Ant &lhs, const Ant &rhs)
{
    return lhs.pos < rhs.pos;
}
int l = 0, r = 0;
int main()
{
#ifdef LOCAL
    freopen("PREV-27.in", "r", stdin);
#endif
    int n; cin >> n;
    l = 0, r = n - 1;
    for(int i = 0; i < n; ++i)
    { 
        cin >> ants[i].pos;
        if(ants[i].pos < 0) ants[i].dir = -1;
        else ants[i].dir = 1;
        ants[i].pos = abs(ants[i].pos);
        ants[i].sick = false;
    } 
    ants[0].sick = true;
    sort(ants, ants + n, compare);
    
    // for(int i = 0; i < n; ++i)
    //     cout << (ants[i].dir > 0 ? "" : "-") << ants[i].pos << " ";
    // cout << endl;

    // 去掉左边和右边能走出去的蚂蚁
    for(; l < n; ++l) if(ants[l].dir > 0) break;
    for(; r >=0; --r) if(ants[r].dir < 0) break;

    // 当还有多只蚂蚁的时候开始模拟
    while(r > l)
    {
        for(int i = l; i <= r; ++i)
            ants[i].pos += ants[i].dir * 1;    
        for(int i = l; i < r; ++i)
        {
            if(ants[i].pos == ants[i + 1].pos)
            {
                
                ants[i].sick = ants[i + 1].sick = ants[i].sick || ants[i + 1].sick;
                ants[i].dir = -1 * ants[i].dir;
                ants[i + 1].dir = -1 * ants[i + 1].dir;
            }
            // [6, -7] -> [ -7,7 ]
            else if(ants[i].pos - ants[i + 1].pos  == 1 && ants[i].dir == 1 && ants[i + 1].dir == -1)
            {
                ants[i].sick = ants[i + 1].sick = ants[i].sick || ants[i + 1].sick;
                ants[i].dir = -1 * ants[i].dir;
                ants[i + 1].dir = -1 * ants[i + 1].dir;
                ants[i + 1].pos = ants[i].pos;
            }
        }
        for(; l < n; ++l) if(ants[l].dir > 0) break;
        for(; r >=0; --r) if(ants[r].dir < 0) break;

        // for(int i = 0; i < n; ++i)
        //     cout << (ants[i].dir > 0 ? "" : "-") << ants[i].pos << " ";
        // cout << endl;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(ants[i].sick) ans += 1;
    cout << ans << endl;
    return 0;
}