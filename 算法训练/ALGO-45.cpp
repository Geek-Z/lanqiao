/**
s的范围限制在5.2以内, 因此计算出5.2以内所有的值, 再使用二分即可找到答案
**/
#include <bits/stdc++.h>
#define EXP 1e-6
using namespace std;
vector<double> nums;
//[l, r]
int getAns(int l, int r, double x)
{
    if(r <= l)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if(x > nums[mid]) return getAns(mid + 1, r, x);
    else return getAns(l, mid, x);
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-45.in", "r", stdin);
#endif
    double s = 0;
    nums.push_back(-1);
    for(int i = 1; s <= 5.20; ++i)
    {
        s += 1.0 / (i + 1);
        nums.push_back(s);
    }
    double x;
    while(cin >> x && x != 0.00)
    {
        int ret = getAns(1, nums.size() - 1, x);
        cout << ret << " card(s)" << endl;
    }
    return 0;
}