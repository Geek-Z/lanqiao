#include <bits/stdc++.h>
using namespace std;
int main()
{
    int K, N;
    unsigned int ans = 0;
    scanf("%d %d", &K, &N);
    int exp = 0;
    while(N)
    {
        ans += (N & 1) * pow(K, exp++); 
        N = N >> 1;
    }
    cout << ans << endl;
    return 0;
}