#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int num[100000];
    int sum[100000];
    long long int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        long long int a;
        cin >> a;
        sum[i] = (sum[i - 1] + a) % k;  // 前缀和, 当sum[i] 为0, 则说明到此能被整除。
        num[sum[i]]++;
        ans += num[sum[i]] - 1;        
    }
    cout << ans + num[0] << endl;
}