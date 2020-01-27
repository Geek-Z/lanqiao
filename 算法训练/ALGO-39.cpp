#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int main()
{
#ifdef LOCAL
    freopen("ALGO-39.in", "r", stdin);
#endif
    int t;
    for(int i = 0; i < 10; ++i)
        cin >>t, nums.push_back(t);
    sort(nums.begin(), nums.end());
    vector<int>::iterator mid = unique(nums.begin(), nums.end()); 
    for(vector<int>::iterator ite = nums.begin(); ite != mid; ++ite)
        cout << *ite << endl;
    return 0;
}