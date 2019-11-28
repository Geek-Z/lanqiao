#include <bits/stdc++.h>
using namespace std;
int N, t, b, e;
int weights[100001];
int head[100001];           /* 邻接表头*/           
int dp[100001][2];     
int m = 0;                  /* 指针*/
struct edge{                /* 邻接表使用的边节点*/
    int v, next;
}edges[200001];


void addEdge(int from, int to)
{
    // 以to为终点的边, 头查的方式插入
    edges[m].v = to;
    edges[m].next = head[from];
    head[from] = m++;

    // 以from为终点的边
    edges[m].v = from;
    edges[m].next = head[to];
    head[to] = m++;
}

void DFS(int root, int pre)
{
    dp[root][0] = 0;
    dp[root][1] = weights[root];

    // 遍历链表
    // cout << root << endl;
    for(int n = head[root]; n != -1; n = edges[n].next){
        int v = edges[n].v;
    // if(root == 1) cout << v <<endl;
        if(v == pre) continue;
        DFS(v, root);     // 后序遍历
        dp[root][0] += max(dp[v][0], dp[v][1]);
        dp[root][1] += dp[v][0];
    }
    //printf("dp[%d][0]  = %d -- dp[%d][1] = %d\n", root, dp[root][0], root ,dp[root][1]);
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-4.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    int ans = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> t, weights[i] = t;
    while(cin >> b >> e)
        addEdge(b, e);
    DFS(1, -1); 
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#define _Max 100010
#define max(a, b) a > b ? a : b

struct point
{
    int v, next;   // v指向这条边的另一个结点（父结点），next指向子结点
} edge[_Max * 2];  // 一条边记录两次，分别以一个点做记录

int head[_Max];    // head 表示邻接表的头
int M;
int dp[_Max][2];   // 使用dp的数组

//添加一个边
void addEdge(int from, int to)
{
    //from结点, 头插法的方式插入
    edge[M].v = to;               // 当前边指向的顶点
    edge[M].next = head[from];    // 为-1则定位叶结点，否则，指向另外一条边
    head[from] = M++;             // 指向他的一条边，增加结点
    
    //to结点
    edge[M].v = from;
    edge[M].next = head[to];      //为-1则定位叶结点，否则，指向另外一条边
    head[to] = M++;               //指向他的一条边，增加结点
    return ;
}

//深度遍历，先深入到叶子结点，然后一层一层往上回升，一直到根结点，即第一个结点（初始pre为－1是因为根结点没有父结点，用－1表示）
void dfs(int x, int pre)
{
    int i = head[x], v;
    for (; i != -1; i = edge[i].next)  //i != -1说明有子结点，则遍历子结点，否则为叶子结点
    {
        v = edge[i].v;
        if (pre == v)  //如果指向的子结点和父结点重合，则说明这个结点是叶子结点，不需要进一步dp
        {
            continue;
        }
        dfs(v, x);     //x可以理解为父结点
        //深度遍历到最里面的叶子结点的父结点   如果父结点选择，则子结点不选择，否则子结点可能选择或者不选择，但是要比较两者哪个大选择哪个
        dp[x][1] += dp[v][0];                   //   父结点（选） ＋＝ 子结点（不选）
        dp[x][0] += max(dp[v][0], dp[v][1]);    //   父结点（不选） ＋＝ max（子结点（不选），子结点（选））
    }
    return ;
}
int main(int argc, const char * argv[])
{
#ifdef LOCAL
    freopen("ALGO-4.in", "r", stdin);
#endif
    int i, n, s, t, tmp;
    scanf("%d", &n);
    M = 0;
    memset(head, -1, sizeof(head));   //初始化每个结点都是独立的没有子结点
    memset(dp, 0, sizeof(dp));
    //输入权值，并且记录在dp[i][1]上，i表示第i个结点，1代表取了这个结点
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &dp[i][1]);
    }
    //输入边，并且添加edge，一个边添加两个edge
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &s, &t);
        addEdge(s, t);
    }
    dfs(1, -1);   //深度优先遍历，从第一个结点开始遍历
    tmp = max(dp[1][0], dp[1][1]);    //求出最大的权值和
    printf("%d\n", tmp);
    return 0;
}
*/