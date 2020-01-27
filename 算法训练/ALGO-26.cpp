#include <bits/stdc++.h>
using namespace std;
vector<int> single(500, 0);
// A X B
vector<int> mul(const vector<int> &lhs, const vector<int> &rhs)
{
    vector<int> ans(500, 0);
    for(int i = 0; i < lhs.size(); ++i)
    {
        for(int j = 0; j < rhs.size(); ++j)
        {
            if(i + j >= 500) continue;
            ans[i + j] += lhs[i] * rhs[j];
        }
    }
    // 处理进位
    int carr = 0;
    for(int i = 0; i < ans.size(); ++i)
    {
        int t = ans[i] + carr;
        ans[i] = t % 10;
        carr = t / 10; 
    }
    if(carr != 0 && ans.size() < 500) ans[ans.size() + 1] = carr;
    return ans;
}

// 2^n
vector<int> getAns(int n)
{
    if(n == 0)
    {
        single[0] = 1;
        return single;
    } 
    if(n == 1)
    {
        single[0] = 2;
        return single; 
    }
    vector<int> temp = getAns(n / 2);
    temp = mul(temp, temp);
    if(n % 2 == 1) temp = mul(temp, single);
/*
    cout << "2^" << n << " = ";
    for(int i = temp.size() - 1; i >= 0 ; --i)
        cout << temp[i];
    cout << endl; 
*/
    return temp;
}

int main()
{
    int p; cin >> p;
    vector<int> ans = getAns(p);
    ans[0] -= 1;
    reverse(ans.begin(), ans.end());
    cout << floor((p * log10(2) + 1)) << endl;
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if((i + 1) % 50 == 0) cout << endl;
    }
    return 0;
}