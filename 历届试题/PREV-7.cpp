#include <bits/stdc++.h>
using namespace std;
int a[50000];
int main()
{
#ifdef LOCAL
    freopen("PREV-7.in", "r", stdin);
#endif
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int L = a[i];
        int R = a[i];
        for(int j = i; j < n; ++j) {
            if(a[j] > R) R = a[j];
            if(a[j] < L) L = a[j];
            if(j - i == R - L) 
                sum++;
        }
    }
    cout << sum << endl;
    return 0;
}