#include <bits/stdc++.h>
using namespace std;
int len,pos=0;
string str;
int dfs()
{
    int num=0,maxx=0;
    while(pos<len)
    {
        if(str[pos]=='(')
        {
            pos++; num+=dfs();
        }
        else if(str[pos]==')') {
            pos++; break;
            
        }
        else if(str[pos]=='|') {
            pos++; maxx=max(num,maxx);
            num=0;

        }
        else {
            pos++; num++;
        }
        
    } maxx=max(num,maxx);
    return maxx;
    
}
int main()
{
#ifdef LOCAL
    freopen("PREV-35.in", "r", stdin);
#endif
    cin>>str;
    len=str.length();
    printf("%d\n",dfs());
    return 0;
    
}