/**
模拟N进制的加法:
1. 将第一个元素初始化到A当中。
2. 将A反转添加到B当中。
3. 模拟A与B的加法, 在放入a当中, 重复2，3步骤

2,3 步骤算一个设置为1个函数

**/
#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
int N;
char A[MAXN], B[MAXN];

void mreverse()
{
    memset(B, 0, sizeof(B));
    int index = 0;
    for(int i = strlen(A) - 1; i >= 0; --i)
        B[index++] = A[i];
    // 当A = 0的时候。
    if(B[0] == '0') return;
    
    // 去除前导0
    for(int i = strlen(B) - 1; i >= 0; --i)
        if(B[i] != '0')
        {
            index = i;
            break;
        }
    B[index + 1] = '\0';
}

bool ishuiwen()
{
    int Alen = strlen(A);
    for(int i = 0; i < Alen / 2; ++i)
    {
        if(A[i] != A[Alen - i - 1])
            return false;
    }
    return true;
}

void step()
{
    // 将A反转到B当中
    mreverse();
    //printf("%s + %s = ", A, B);
    // 模拟加法
    int index = 0, carr = 0, Alen = strlen(A), Blen = strlen(B);
    while(index < Alen || index < Blen)
    {
        int t = carr;
        if(index < Alen)
        {
            if(isdigit(A[index])) t += A[index] - '0';
            else t += A[index] - 'A' + 10;
        }

        if(index < Blen)
        {
            if(isdigit(B[index])) t += B[index] - '0';
            else t += B[index] - 'A' + 10;
        }
        int n = t % N;
        A[index++] = n <= 9 ? n + '0' : n - 10 + 'A';
        carr = t / N;
    }

    // 处理剩余的进位
    if(carr != 0) A[index] = carr + '0';
    //printf("%s\n", A);
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-14.in", "r", stdin);
#endif
    scanf("%d %s", &N, A);
    reverse(A, A + strlen(A));
    if(ishuiwen())
    {
        printf("STEP=0\n");
        return 0;
    }
    int i;
    for(i = 1; i <= 30; ++i)
    {
        //printf("STEP%d : ", i);
        step();
        if(ishuiwen()) break;
    }
    if(i != 31)
        printf("STEP=%d\n", i);
    else 
        printf("Impossible!");
    return 0;
}