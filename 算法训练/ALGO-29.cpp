#include <bits/stdc++.h>
using namespace std;
struct Section
{
    int l, r;
}sections[100];
bool compare(const Section &lhs, const Section &rhs)
{
    return (lhs.l < rhs.l) || (lhs.l == rhs.l && lhs.r < rhs.r);
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-29.in", "r", stdin);
#endif
    int L, M; cin >> L >> M;
    for(int i = 0; i < M; ++i)
        cin >> sections[i].l >> sections[i].r;
    sort(sections, sections + M, compare);
    int left = sections[0].l, right = sections[0].r;
    for(int i = 1; i < M; ++i)
    {
        // 有交集, 小心包含的情况
        if(sections[i].l <= right) right = max(sections[i].r, right);
        
        // 没有交集
        else
        {
            L = L - (right - left + 1);
            left = sections[i].l;
            right = sections[i].r;
        }
    }
    L = L - (right - left + 1);
    cout << (L + 1) << endl;
    return 0;
}