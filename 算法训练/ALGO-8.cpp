#include <bits/stdc++.h>
#define N 270000
using namespace std;
int a[N];
struct Node{
    int l, r, sum, max;
}tree[N];

void build(int i, int l, int r)
{
    tree[i].l = l;
    tree[i].r = r;
    
    // 叶子节点
    if(l == r)
    {
        tree[i].max = a[l];
        tree[i].sum = a[l];
        // printf("[%d %d] sum is %d and max is %d\n", tree[i].l, tree[i].r, tree[i].sum, tree[i].max);
        return;
    }

    // 一分为2分别构建左子树和右子树
    int mid = (l + r) >> 1;
    build(i*2, l, mid);
    build(i*2+1, mid + 1, r);
    tree[i].sum = tree[i*2].sum + tree[i*2 + 1].sum;
    tree[i].max = max(tree[i*2].max, tree[i*2+1].max);
    // printf("[%d %d] sum is %d and max is %d\n", tree[i].l, tree[i].r, tree[i].sum, tree[i].max);
}

// 目标区间是l和r
int search(int i, int l, int r)
{
    // 如果此节点的区间包含在目标区间当中, 则直接返回当前区间的值
    if(tree[i].l >= l && tree[i].r <= r) return tree[i].sum;
    
    // 如果此加点的区间与目标区间没有交集, 则返回0
    if(tree[i].r < l || tree[i].l > r) return 0;

    // 剩下的情况是有交集的情况
    int s = 0;
    if(tree[2*i].r >= l) s += search(2 * i, l, r);
    if(tree[2*i + 1].l <= r) s += search(2 * i + 1, l, r);
    return s;    
}

int searchMax(int i, int l, int r)
{
    // 如果当前节点的区间在目标区间当中, 则直接返回当前区间的最大值
    if(tree[i].r <= r && tree[i].l >= l)
    {
        // printf("[%d %d] 's max is %d\n", tree[i].l, tree[i].r, tree[i].max);
        return tree[i].max;
    }
    // 如果当前节点的区间不在目标区间当中, 则返回INT_MIN;
    if(tree[i].l > r || tree[i].r < l) return INT_MIN;
    
    // 剩下是有交集的情况
    int ret = INT_MIN;
    if(tree[2*i].r >= l) ret = max(ret, searchMax(2 * i, l, r));
    if(tree[2*i + 1].l <= r) ret = max(ret, searchMax(2 * i + 1, l, r));
    return ret;
}

// 对disc 位置上的元素 + k, 后归并过程当中更新父亲节点当中的sum和max即可。
void add(int i, int disc, int k)
{
    
    // 如果是disc这个节点
    if(tree[i].l == tree[i].r)
    {
        tree[i].sum = k;
        tree[i].max = k;
        return;
    }

    if(disc <= tree[2*i].r) add(i*2, disc, k);
    else add(i*2 + 1, disc, k);
    tree[i].max = max(tree[i*2].max, tree[i*2 + 1].max);
    tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-8.in", "r", stdin);
    freopen("ALGO-8.out", "w", stdout);
#endif
    int n, m, p, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while(m--)
    {
        scanf("%d %d %d", &p, &x, &y);
        if(p == 1)
        {
            add(1, x, y);
        }
        else if(p ==2)
        {
            int sum = search(1, x, y);
            printf("%d\n",sum);
        }
        else
        {
            int ret = searchMax(1, x, y);
            printf("%d\n", ret);
        }
    }
    return 0;
}