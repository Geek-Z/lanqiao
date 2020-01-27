#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
char Node[MAXN];
int LEFT[MAXN];
int RIGHT[MAXN];
int in = 0;
int newNode() { return in++;}
int build(const string& mid, const string &post, int &cur, int l, int r)
{
    int sub = newNode();
    Node[sub] = post[cur];
    
    // 找到分割点
    int m = -1;
    for(int i = l; i < r; ++i)
        if(mid[i] == post[cur]) 
        {
            m = i;
            break;
        }
    if(m + 1 == r) RIGHT[sub] = -1;
    else RIGHT[sub]= build(mid, post, --cur, m + 1, r);
    if(l == m) LEFT[sub] = -1;
    else LEFT[sub] = build(mid, post, --cur, l, m);
    return sub; 
}
void preOrder(int i)
{
    if(i != -1)
    {
        cout << Node[i];
        preOrder(LEFT[i]);
        preOrder(RIGHT[i]);
    }
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-20.in", "r", stdin);
#endif
    string mid, post;
    cin >> mid >> post;
    int cur = post.size() - 1;
    int index = build(mid, post, cur, 0, post.size());
    // for(int i = 0; i < post.size(); ++i)
    // {
    //     cout << Node[i] << "  " << LEFT[i] << "   " << RIGHT[i] << endl;
    // }
    preOrder(0);
    cout << endl;
    return 0;
}