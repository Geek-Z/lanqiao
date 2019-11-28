#include <bits/stdc++.h>
using namespace std;

int subset(int cur, int n, vector<int> &ans)
{
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;    
    for(int i = cur; i < n; ++i) {
        ans.push_back(i + 1);
        subset(i + 1, n, ans);
        ans.pop_back();
    }
}

int main()
{
    vector<int> ans;
    subset(0, 3, ans);
    return 0;
}
