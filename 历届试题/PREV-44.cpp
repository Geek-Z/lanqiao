#include <bits/stdc++.h>
using namespace std;
string b, e;
struct Node
{
    string str;
    int step;
    Node(string s, int st){str = s; step = st;}  
    Node(){}
};
map<string, int> filter;            // 去掉BFS当中重复出现的顶点, 因为从此结点的已经计算过了。
int dir[6] = {-3, -2, -1, 1, 2, 3}; // * 能跳转到的位置
int BFS()
{
    int ans = 0;
    queue<Node> Q;
    Q.push(Node(b, 0));
    filter[b] += 1;
    
    while(!Q.empty())
    {
        Node node = Q.front(); Q.pop();
        // cout << node.str << endl;
        int ii = node.str.find("*");
        for(int i = 0; i < 6; ++i)
        {
            string s = node.str;
            int jj = ii + dir[i];
            // 可以跳跃
            if(jj >= 0 && jj < s.size())
            {
                swap(s[ii], s[jj]);

                // 此次跳远和最终状态不同
                if(filter[s] > 0 ) continue;
                filter[s] += 1;
                
                // 跳跃到最终状态
                if(s == e)
                {
                    ans = node.step + 1;
                    break;
                }
                Q.push(Node(s, node.step + 1));    
            }
        }
    }
    return ans;
}
int main()
{
#ifdef LOCAL
    freopen("PREV-44.in", "r", stdin);
#endif
    cin >> b >> e;
    int ans = BFS();
    cout << ans << endl;
    return 0;
}