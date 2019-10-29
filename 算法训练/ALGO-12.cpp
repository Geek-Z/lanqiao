#include <bits/stdc++.h>
using namespace std;

string ret[3] = {"0", "1", "2"};

string func(int num)
{
    string ans = "";
    if(num == 0 || num == 2)
        return ret[num];

    bool first = true;
    while(num != 0)
    {
        int t = 1, k = 0;
        while((t << 1) <= num){
            t = t << 1;
            k += 1; 
        }
        num = num - t;
        if(!first) ans += "+";
        if(k == 1)  ans += "2";
        else ans = ans + "2(" + func(k) + ")";
        first = false;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t; cin >> t;
    string ans = func(t);
    cout << ans << endl;
    return 0;
}
