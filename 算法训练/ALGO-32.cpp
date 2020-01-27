#include <bits/stdc++.h>
using namespace std;
char number[30];
int main()
{
#ifdef LOCAL
    freopen("ALGO-32.in", "r", stdin);
#endif
    int s, t, w, times = 5;
    scanf("%d %d %d", &s, &t, &w);
    scanf("%s", number);
    while(times--)
    {
        bool flag = false;
        
        for(int i = w - 1; i >= 0; i--)
        {
            //替换该数字需要字母的个数满不满足供给
            if(t - (number[i] - 'a' + 1) >= w - i)
            {
                flag = true;
                
                // 开始替换
                number[i] += 1;
                for(int index = i + 1; index < w; ++index)
                {
                    number[index] = number[index - 1] + 1;
                }
                printf("%s\n", number);
                break;
            }
        }

        if(!flag) break;
    }
    return 0;
}