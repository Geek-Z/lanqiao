#include <bits/stdc++.h>
using namespace std;
string getAns(int n)
{
    string ans;
    while(n != 0)
    {
        int rest = n % 26;
        n = n / 26;
        if(rest == 0) rest = 26, n-=1;
        ans.append(1, rest -1 + 'A');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n; cin >> n;
    string ans = getAns(n);
    cout << ans << endl;
    return 0;
}