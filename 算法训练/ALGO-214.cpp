/*
    1. 先建立DAG
*/
#include <bits/stdc++.h>
using namespace std;
// BFS当中的顶点
struct Node
{   
    char type; 
    int need;
    int state;
    void reset() {type=='n' ? need = 1 : need = 2;}
    Node(){need = 0;}
    Node(char t) {(type = t) == 'n' ? need = 1 : need = 2;}  
};
// 给结点添加一个key
map<string, Node> nodes;

// 邻接表
map<string, vector<string> > graph;
vector<string> outkeys;
vector<int> out;
vector<int> in;
string toString(int n)
{
    string ans;
    while(n)
    {
        ans.append(1, (n % 10) + '0');
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-214.in", "r", stdin);
#endif
    int N, G, U;
    while(cin >> N >> G >> U && N !=0 &&G != 0 && U != 0)
    {
        // 清空
        nodes.clear(); graph.clear(); outkeys.clear();
        // 先输入每个门
        for(int i = 1; i <= G; ++i)
        {
            string gate = "g";
            gate.append(toString(i));            
            
            char type; cin >> type;
            string gate1, gate2;

            // 状态为非, 则只用读取一个门
            if(type == 'n')
            {
                cin >> gate1;
                graph[gate1].push_back(gate);
            }
            else 
            {
                cin >> gate1 >> gate2;
                graph[gate1].push_back(gate);
                graph[gate2].push_back(gate);
            }
            if(graph.find(gate) == graph.end() )graph[gate] = vector<string>();
            nodes[gate] = Node(type);
        }

        // 记录输出顺序
        for(int i = 0; i < U; ++i)
        {
            int t; cin >> t;
            outkeys.push_back(string("g").append(toString(t)));
        }

        int group = 0; cin >> group;
        while(group--)
        {
            for(int i = 0; i < N + U; ++i)
            {
                
            }
        }
        
        // 输出图的信息
        for(map<string, vector<string> >::iterator ite = graph.begin(); ite != graph.end(); ++ite)
        {
            cout << ite->first << " : ";
            for(int i = 0; i < ite->second.size(); ++i)
            {
                cout << ite->second[i] << " ";
            }
            cout << endl;
        }

        for(map<string, Node>::iterator ite = nodes.begin(); ite != nodes.end(); ++ite)
        {
            cout << ite->first << " type : " << ite->second.type << "  need : " << ite->second.need << endl;
        }
        break;
    }
    return 0;
}