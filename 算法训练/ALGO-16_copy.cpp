#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, r, temp, t1;
    cin >> n >> r;
    int a = n;
    vector<char>ans;
    while(n != 0)
    {
        temp = n % r;
        t1 = n;
        n /= r;
        while(temp < 0)
        {
            n++;
            temp = t1 - n * r;
        }
        
        /*cout << temp << " " << n << endl;
        system("pause");*/
        if(temp > 9)
        {
            ans.push_back(temp - 10 + 'A');
        }
        else if(temp >= 0)
        {
            ans.push_back(temp + '0');
        }

    }
    cout << a << "=";
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << "(base" << r << ")";
}