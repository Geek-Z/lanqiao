#include <bits/stdc++.h>
using namespace std;

void printTreeLine(int level, int line)
{
    
    int maxLine = 9 + 4 * (level - 1);
    int cnt ;
    // 第一行和倒数一一行
    if(line == 1 || line == maxLine)
    {
        printf(".."); cnt = 5 + 4 * (level - 1);
        for(int i = 0; i< cnt; ++i) printf("$");
        printf("..");
    
    // 第二行和倒数第二行
    } else if(line == 2 || line == maxLine - 1) {
    
        printf("..$"); cnt = 3 + 4 * (level - 1);
        for(int i = 0; i< cnt; ++i) printf(".");
        printf("$..");

    // 第三行和倒数第三行
    } else if(line == 3 || line == maxLine - 2)
    {
        printf("$$$."); cnt = 1 + 4 * (level - 1);
        for(int i = 0; i< cnt; ++i) printf("$");
        printf(".$$$");
    }
}

// 输出每一行
void getLine(int level , int line)
{
   // 递归出口
   int maxLine = 9 + 4*(level - 1);
   
   // 前三行可以直接计算出来, 能直接使用
   if(line <= 3 || line >= maxLine - 2)
   {
       printTreeLine(level, line);
   } else if(level == 1) {
       if(line == 4 || line == 6) printf("$...$...$");
       if(line == 5) printf("$.$$$$$.$");
   }
   else
   {
       printf("$.");
       getLine(level - 1, line - 3 + 1);
       printf(".$");
   }
}


int main()
{
#ifdef LOCAL
    freopen("PREV-2.out", "w", stdout);
#endif
    int level;
    scanf("%d", &level);
    int maxLine = 9 + (level - 1) * 4;
    for(int i = 1; i <= maxLine; ++i)
    {
        getLine(level, i);
        printf("\n");
    }
    return 0;
}