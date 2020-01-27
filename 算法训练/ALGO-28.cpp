#include <bits/stdc++.h>
#define MAXN 10000 + 5
using namespace std;
int a[MAXN], n, m;
int main()
{
#ifdef LOCAL
    freopen("ALGO-28.in", "r", stdin);
#endif
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    while(m--)
    {
        // 寻找第一个顺序的位置
        for(int i = n - 1; i > 0; --i)
        {
            if(a[i - 1] < a[i])
            {
                // 寻找第一个比a[i - 1] 的元素在 [i, ...] 之间
                for(int j = n - 1; j >= i; --j)
                {
                    if(a[j] > a[i - 1])
                    {
                        swap(a[j], a[i - 1]);
                        break;
                    }
                }
                sort(a + i, a + n);
                break;
            }
        }
    }
    bool first = true;
    for(int i = 0; i < n; ++i)
    {
        cout << (first ? "" : " ") << a[i], first = false;
    }
    return 0;
}