#include <bits/stdc++.h>
#define MAXN 100 + 5
using namespace std;
int dirc = -1, m, n, x, y, s, k;
char t;
// 上右下左
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int board[MAXN][MAXN];
int newDir(int color)
{
    // 如果是黑色格子, 则顺时针旋转90度
    if(color == 1) return (dirc + 1) % 4;
    // 如果是白色格子, 则逆时针旋转90度
    else return (dirc + 3) % 4;
}
int main()
{
#ifdef LOCAL
    freopen("PREV-33.in", "r", stdin);
#endif
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
        cin >> board[i][j];
    cin >> x >> y >> t >> k;
    if(t == 'U') dirc = 0;
    else if(t == 'R') dirc = 1;
    else if(t == 'D') dirc = 2;
    else dirc = 3;
    
    while(k--)
    {
        // 先根据当前位置颜色计算新的方向
        dirc = newDir(board[x][y]);
        board[x][y] = !board[x][y];
        x = x + dr[dirc], y = y + dc[dirc];
    } 
    cout << x << " " << y << endl;   
    return 0;
}