#include <bits/stdc++.h>
using namespace std;
int getOne(int n) {
    int ans = 0;
    while(n){
        if(n % 10 == 1) 
            ans += 1;
        n /= 10;
    }
    return ans;
}
int main()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += getOne(i);
    }
    cout << ans << endl;
    return 0;
}