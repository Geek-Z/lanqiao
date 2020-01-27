#include <bits/stdc++.h>
using namespace std;
// 0 是纯 0 , 1 是纯 1, 2 是混合
int getAns(int l, int r, string s)
{
    if(r - l == 1)
    {
        if(s[l] == '0')
        {
            cout << "B";
            return 0;
        }
        else
        {
            cout << "I";
            return 1;
        }
    }
    int mid = l + (r - l ) / 2;
    int lr = getAns(l, mid, s);
    int rr = getAns(mid , r, s);
    if(lr == 1 && rr == 1){ cout << "I"; return 1;}
    else if(lr == 0 && rr == 0){ cout << "B"; return 0;}
    else {cout << "F"; return 3;}
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-27.in", "r", stdin);
#endif
    int n; cin >> n;
    string str; cin >> str;
    getAns(0, str.size(), str);
    return 0;
}