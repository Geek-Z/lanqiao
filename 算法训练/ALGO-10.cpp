#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;
vector<int> a, b, c;   // 交, 并, 差
int main()
{
#ifdef LOCAL
    freopen("ALGO-10.in", "r", stdin);
#endif
    int n, m, t;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &t), A.push_back(t);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) scanf("%d", &t), B.push_back(t);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int indexA = 0, indexB = 0;
    while(indexA < n && indexB < m)
    {
        // 跳过A当中的元素, A添加到并集当中, 添加到余集当中
        if(A[indexA] < B[indexB]) c.push_back(A[indexA]), b.push_back(A[indexA]), ++indexA;
        // 两个元素相等, 只添加一次到交集当中, 并添加到并集当中
        else if(A[indexA] == B[indexB]) b.push_back(A[indexA]), a.push_back(A[indexA]), ++indexA, ++indexB;
        // 跳过B元素, 该元素添加到并集当中，
        else b.push_back(B[indexB]), ++indexB;
    }
    // A中如果有剩余, 则添加到c中, 并添加到并集当中
    while(indexA < n) c.push_back(A[indexA]), b.push_back(A[indexA]), ++indexA;

    // B 中如果有剩余, 则添加到并集当中
    while(indexB < m) b.push_back(B[indexB]), ++indexB;
    
    bool first = true;
    for(int i = 0; i < a.size(); ++i) printf("%s%d", first ? "" : " ", a[i]), first = false;
    if(!first) printf("\n");
    first = true;
    for(int i = 0; i < b.size(); ++i) printf("%s%d", first ? "" : " ", b[i]), first = false;
    if(!first) printf("\n");
    first = true;
    for(int i = 0; i < c.size(); ++i) printf("%s%d", first ? "" : " ", c[i]), first = false;
    if(!first) printf("\n");
    return 0;
}