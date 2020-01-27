#include <bits/stdc++.h>
using namespace std;
long long kto10(string str, int k)
{
    long long ans = 0, exp = 1;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        int x = str[i] > '9' ? str[i] - 'A' + 10 : str[i] - '0';
        ans += x * exp;
        exp *=k;
    }
    return ans;
}
string tenToK(long long n, int k)
{
    if(n == 0) return "0";
    string ans;
    while(n)
    {
        int t = n % k;
        ans.append(1, t > 9 ? t - 10 + 'A' : t + '0');
        n /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
#ifdef LOCAL
    freopen("PREV-55.in", "r", stdin);
#endif
    int n, k = 10;
    long long lhs = -1, rhs = -1;
    string OPE, NUM, ins;
    cin >> n;
    while(n--)
    {
        cin >> ins;
        if(ins == "CLEAR")
            NUM = "0", lhs = 0;
        else if(ins == "CHANGE")
            cin >> k;
        else if(ins == "EQUAL")
        {
            cout << tenToK(lhs, k) << endl;
        }
        else if(ins == "NUM")
        {
            cin >> NUM;
            if(OPE == "") lhs = kto10(NUM, k);
            // 在运算符之后输入数字, 则表明需要发生计算
            else
            {
                rhs = kto10(NUM, k);
                //cout << lhs << " " <<  OPE << " " << rhs << " = ";
                if(OPE == "ADD") lhs += rhs;
                else if(OPE == "SUB") lhs -= rhs;
                else if(OPE == "MUL") lhs *= rhs;
                else if(OPE == "DIV") lhs /= rhs;
                else if(OPE == "MOD") lhs %= rhs;
                //cout << lhs << endl;
                rhs = -1;
                OPE = "";
            }
        } else OPE = ins;
    }
    return 0;
}