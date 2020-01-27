#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    int n, t; cin >> n;
    while(n--) cin >>t, nums.push_back(t);
    sort(nums.begin(), nums.end(), compare);
    bool first = true;
    for(int i = 0; i < nums.size(); ++i)
        cout << (first ? "" : " ") << nums[i], first = false;
    cout << endl; 
}