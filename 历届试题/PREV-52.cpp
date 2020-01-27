#include <bits/stdc++.h>
/*
    模拟竖式除法, 当出现循环节 或 除尽的时候的是否终止循环
*/
using namespace std;
string bits = "";            // 存放循环节当中的小数
map<int, int> indexs;                   
int beg = 0;
int main()
{
    bool inf = true;         // 标记获得的小数是有限小数还是无限小数, false为有限小数
    int a, b, n, i = 0, len = 0;
    cin >> a >> b >> n;
    a = a % b;
    //indexs[a] = i++;
    if(a == 0) inf = false;
    while(a != 0)
    {
        //cout << a << " / " << b << " = ";
        a *= 10;
        int shang = a / b;
        a = a % b;
        //cout << shang << "MOD is " << a << endl;
        // 是用余数来判断循环节
        if(a != 0 && indexs.find(a) != indexs.end()) 
        {
            beg = indexs[a];
            len = i - beg;
            break;
        }
        indexs[a] = i++;
        bits.append(1, shang + '0');
    }
    if(a == 0) inf = false;
    int cnt = bits.size();
    //cout << bits << endl;
    //cout << beg << endl;
    //cout << len << endl;
    if(inf)
    {
        if(n - 1 < cnt) cout << bits[n - 1]; else cout << bits[((n - 1 - beg))% len + beg ];
        if(n < cnt) cout << bits[n]; else cout << bits[((n - beg))% len + beg];
        if(n + 1 < cnt) cout << bits[n + 1]; else cout << bits[((n + 1 - beg))% len + beg ];
    }
    else
    {
        if(n - 1 < cnt) cout << bits[n - 1]; else cout << 0;
        if(n < cnt) cout << bits[n]; else cout << 0;
        if(n + 1 < cnt) cout << bits[n + 1]; else cout << 0;
    }
    
    return 0;
}
/*
32989690721649484536082474226804123711340206185567010309278350515463917525773195876288659793814
beg = 29
(111 - 29) % a
*/