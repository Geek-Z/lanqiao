#include <bits/stdc++.h>
using namespace std;
int getCnt(int n)
{
    int ans =  0;
    while(n) ans += n % 2, n /= 2;
    return ans;
}
int main()
{
    int L, R, ans = 0;
    cin >> L >> R;
    for(int i = L; i <= R; ++i)
        ans += getCnt(i);
    cout << ans << endl;
    return 0;
}