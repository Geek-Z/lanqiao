#include <bits/stdc++.h>
using namespace std;
list<int> doing;
queue<int> wait;
int main()
{
#ifdef LOCAL
    freopen("ALGO-38.in", "r", stdin);
#endif
    int t = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int temp; cin >> temp;
        if(i < m) doing.push_back(temp);
        else wait.push(temp); 
    }
    int zero = 0;
    while(!doing.empty())
    {
        zero = 0;
        t++;
        for(list<int>::iterator b = doing.begin(); b != doing.end();)
        {
            --(*b);
            if(*b == 0) b = doing.erase(b), zero++;
            else ++b;
        }
        
        // 补充人数
        for(int i = 0; i < zero; ++i)
        {
            if(!wait.empty())
            {
                doing.push_back(wait.front());
                wait.pop();
            }
        }    
    }
    cout << t << endl;
    return 0;
}