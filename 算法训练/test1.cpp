
/**
    负数进制的转换
**/
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
int main()
{
    printf("%.100lf", 129/97.0);
    return 0;
}
/*
922337202603578112
922337202603578091
*/