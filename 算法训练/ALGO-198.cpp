#include <bits/stdc++.h>
using namespace std;
#define MAXN 20
struct Point 
{
    int xi, yi, vi, li;
}STK[MAXN], Eles[MAXN];

vector<Point> convex;

int judge(Point &a, Point &b, Point&c)
{
    return (b.xi - a.xi) * (c.yi - a.yi) - (c.xi - a.xi) * (b.yi - a.yi); 
}

double dist(Point &a, Point &b) 
{
    return sqrt((a.xi - b.xi) * (a.xi - b.xi) * 1.0 + (a.yi - b.yi) * (a.yi - b.yi));
}

// return a < b
bool comp2(Point &a, Point &b)
{
    int t = judge(convex[0], a, b);
    if(t > 0 || (t == 0 && dist(convex[0], a) <= dist(convex[0], b))) return true;
    else return false;
}

double convex_hull()
{
    if(convex.size() == 1) return 0.00;
    else if(convex.size() == 2) return 2 * dist(convex[0], convex[1]);
    for(int i = 0; i < convex.size(); ++i)
   		if(convex[i].yi < convex[0].yi || (convex[i].yi == convex[0].yi && convex[i].xi < convex[0].xi)) 
		   swap(convex[0], convex[i]);
    sort(convex.begin() + 1, convex.end(), comp2);
    
    int top = -1;
    STK[++top] = convex[0]; 
    STK[++top] = convex[1]; 

    for(int i = 2; i < convex.size(); ++i) {
   		while(judge(STK[top - 1], STK[top], convex[i]) < 0)
            top--;
        STK[++top] = convex[i];     
    }
    
    // getLength
    double s = 0;
    for(int i = 1; i <= top; ++i) 
        s += dist(STK[i - 1], STK[i]);
    s += dist(STK[top], convex[0]);
    return s;
}
int main()
{
#ifdef LOCAL
    freopen("ALGO-198.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); 
    int n, k = 0;
	while(cin >> n && n != 0){
		k++;
		int xi, yi, vi, li;
	    for(int i = 0; i < n; ++i)
	    	cin >> Eles[i].xi >> Eles[i].yi >> Eles[i].vi >> Eles[i].li;  

	   //浜岃繘鍒舵灇涓?
		int minVal = INT_MAX; int remainS = -1; int size = 0; double rest = 0.0;
		for(int s = 0; s < (1 << n) - 1; ++s) {
		  	convex.clear();
		  	int ts = 0;
		    double val = 0.0, length = 0.0;
		    for(int i = 0; i < n; ++i) {
		        if(s & (1 << i)) val += Eles[i].vi, length += Eles[i].li, ts += 1;
		        else convex.push_back(Eles[i]);
		    }
		    // 璁＄畻鍑稿寘
		    if(val > minVal) continue;						// 很关键的一步。 
		    double needLength = convex_hull();
		    if(length >= needLength)
		         if(val < minVal) minVal = val, remainS = s, size = ts, rest = length - needLength;
		         else if(val == minVal)
		         	if(ts < size) remainS = s, size = ts, rest = length - needLength;
		}
	
	    // 输出
		printf("Forest %d\n", k);
		printf("Cut these trees:");
		for(int i = 0; i < n; ++i)
	        if(remainS & (1 << i)) printf(" %d", i + 1);
		printf("\n");
		printf("Extra wood: %.2lf\n\n", rest);
	}
   return 0;
}
