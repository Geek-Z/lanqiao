#include<iostream>
#include<cstring>
using namespace std;
 
int vis[10];
int s[10];
int sum;
int num;
 
void del(int s[])
{
    int a,b,c;
    for(int i=1;i<=9;i++)
    {
        a=0;
        for(int j=1;j<=i;j++)
        {
            a=a*10+s[j];
        }
        if(a<num)
        {
            for(int j=(9-i)/2+i;j<=8;j++)
            {
                b=0;
                c=0;
                for(int h=i+1;h<=j;h++)
                    b=b*10+s[h];
                for(int h=j+1;h<=9;h++)
                    c=c*10+s[h];
                if(b%c==0&&a+b/c==num)
                    sum++;
            }
        }
    }
}
 
void dfs(int st,int n)//全排列
{
    if(st==n)
        del(s);
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(!vis[i])
            {
                s[st]=i;
                vis[i]=1;
                dfs(st+1,n);
                vis[i]=0;
            }
        }
    }
}
 
int main()
{
    cin>>num;
    memset(vis,0,sizeof(vis));
    sum=0;
    dfs(1,10);
    cout<<sum<<endl;
    return 0;
}