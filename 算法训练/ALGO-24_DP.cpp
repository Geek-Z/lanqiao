#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
char ch[10][20];
char ci[6][20];
int cnt=0;
bool pipei(int i,int j,int u,int &ii,int &jj)
{
    int len=strlen(ci[u]);
    for(int k=1;k<len;k++)
    {
        if(j+k>19)
        {
            i++;
            j=-k;
        }
        if(ch[i][j+k]!=ci[u][k])
        return false;
    }
    ii=i;
    jj=j+len-1;
    return true;
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-24.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    int p,k,s;
    scanf("%d%d",&p,&k);
    for(int i=0;i<p;i++)
    {   getchar();
        for(int j=0;j<20;j++)
        scanf("%c",&ch[i][j]);
    }
    scanf("%d",&s);
    getchar();
    int flag;
    for(int i=0;i<s;i++)
    {
        scanf("%s",ci[i]);
    }
    int maxi=0,maxj=0,ii,jj;
    for(int i=0;i<p;i++)
    for(int j=0;j<20;j++)
    {   flag=0;
        for(int u=0;u<s;u++)
        if(ch[i][j]==ci[u][0])
        {
            if(pipei(i,j,u,ii,jj))
            {
                if(maxi<ii||(maxi==ii&&maxj<jj))
                 {maxi=ii;
                 maxj=jj;}
             cnt++;
             flag=1;
             break;
            }
        }
        if(flag==0&&k>1&&(i>maxi||(i==maxi&&j>maxj)))
        k--;
    }
    printf("%d\n",cnt-k+1);
    return 0;
}