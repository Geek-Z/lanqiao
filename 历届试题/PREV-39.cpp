#include <bits/stdc++.h>
using namespace std;
char buffer[32];
char temp[32];
set<string> filter;
vector<string> ans;

// y 可能取值 [60, 99] - [00, 59]
// m 可能取值 [1, 12]
// d 可能取值 [1, 31]
void getDate(int y, int m, int d)
{
    if((y >= 60 && y <= 99 || y >= 0 && y <= 59) && (m <= 12 && m >= 1) && (d >= 1 && d <= 31))
    { 
        if(y >= 60) y += 1900;
        else y += 2000;
        
        // 闰年的判断
        if(((y % 4) == 0 && (y % 100) != 0) || (y % 400) == 0)
        {if(m == 2 && d > 29) return;}
        else
        {if(m ==2 && d > 28) return;}

        
        sprintf(temp, "%d-%02d-%02d", y, m, d);
        string t(temp);
        if(filter.count(t) == 0 ) ans.push_back(string(temp)), filter.insert(t);
    }
}



int main()
{
#ifdef LOCAL
    freopen("PREV-39.in", "r", stdin);
#endif
    int y, m, d;
    scanf("%s", buffer);
    //年月日的方式录入
    sscanf(buffer, "%d/%d/%d", &y, &m, &d); 
    getDate(y, m, d);

    // 月日年的方式录入
    sscanf(buffer, "%d/%d/%d", &m, &d, &y);
    getDate(y, m, d);
    
    // 日月年的方式录入
    sscanf(buffer, "%d/%d/%d", &d, &m, &y);
    getDate(y, m, d);
    
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    return 0;
}