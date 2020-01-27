/**
负数进制的转换
**/
#include <bits/stdc++.h>
using namespace std;
char ans[100 + 5];
int main()
{
    int n, base, t;
    cin >> n >> base;
    t = n;
    int index = 0;
    while(n)
    {
        int r = n % base;
        int t1 = n;
        n = n / base;
    
        // 将余数修正为正数, 并将增大商
        while(r < 0)
        {
            n++;
            r = (t1 - n * base);
        }
        ans[index++] = (r <= 9 ? r + '0' : r - 10 + 'A');
    }
    printf("%d=", t);
    for(int i = index - 1; i >=0; --i) printf("%c", ans[i]);
    printf("(base%d)\n", base);
    return 0;
}