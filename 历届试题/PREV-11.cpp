#include <bits/stdc++.h>
#define MAXN 100 + 5

using namespace std;

int NODE[MAXN], LEFT[MAXN], RIGHT[MAXN];
int index = 1;
int newNode() { return index++;}

// 向排序二叉树当中插入元素, 需要先设置好根节点才行
int insert(int root, int val)
{
    if(root == -1)
    {
        int node = newNode();
        NODE[node] = val;
        return node;
    }    
    else
    {-
        if(val > NODE[root]) RIGHT[root] = insert(RIGHT[root], val);
        else LEFT[root] = insert(LEFT[root], val);
        return root;
    }
}

void print(int root, string t)
{
    if(root == -1) return;
    else
    {   
        cout << t;
        string s = t.append("...");
        if(RIGHT[root] != -1) print(RIGHT[root], s);
        if(root == 1) cout << NODE[root] << "-";
        else cout << "|" << NODE[root] << "-";
        cout << endl;
        if(LEFT[root] != -1) print(LEFT[root], s);
    }
}

int main()
{
#ifdef LOCAL
    freopen("PREV-11.in", "r", stdin);
#endif
    for(int i = 0; i < MAXN; ++i) LEFT[i] = -1;
    for(int i = 0; i < MAXN; ++i) RIGHT[i] = -1;
    int val;
    cin >> val;
    NODE[newNode()] = val;
    while(cin >> val) insert(1, val);
    print(1, "");
    return 0;
}