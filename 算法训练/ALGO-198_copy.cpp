#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
const int esp = 1e-10;
const int maxn = 20;
const int INF = 1<<30;
#define zero(a) (fabs((double)(a)) < esp)
using namespace std;

int n;
struct node{
    int x;
    int y;
    int v;
    int len;
}e[maxn];

vector<node>a;
int judge(node a,node b,node c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

double dis(node a,node b){
    return sqrt(1.00*(b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

int cmp(node p1,node p2){
    double x = judge(a[0],p1,p2);
    if(x > 0 || (zero(x) && dis(a[0],p1) < dis(a[0],p2)))  return 1;
    return 0;
}

double Grham(int len){
    if(a.size() == 1)   return len;
    else if(a.size() == 2)  return len-2*dis(a[0],a[1]);
    
    // 只为找到顶点最小 
	for(int i = 1 ; i < a.size() ; i++){
        if(a[i].y < a[0]. y || (a[i].y == a[0].y && a[i].x < a[0].x))   swap(a[0],a[i]);
    }
    sort(a.begin()+1,a.end(),cmp);
    vector<node>s;
    s.push_back(a[0]);
    s.push_back(a[1]);
    s.push_back(a[2]);
    for(int i = 3 ; i < a.size() ; i++){
        while(s.size() >= 2 && judge(s[s.size()-2],s[s.size()-1],a[i]) < esp)   s.pop_back();
        s.push_back(a[i]);
    }
    s.push_back(s[0]);
    double ans = 0;
    for(int i = 0 ; i < s.size()-1 ; i++){
        ans += dis(s[i],s[i+1]);
    }
    return len-ans;
}

int main(){
#ifdef LOCAL
	freopen("ALGO-198.in", "r", stdin);
#endif
    int cas = 0;
    while(~scanf("%d",&n) && n){
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].v,&e[i].len);
        }
        int best_val = INF,best_num,best_state;
        double best_extra;
        for(int i = 1 ; i < (1<<n)-1 ; i++){
            a.clear();
            int tmp_val = 0,tmp_len = 0;
            for(int j = 0 ; j < n ; j++){
                if(!((1<<j)&i)) a.push_back(e[j]);
                else{
                    tmp_val += e[j].v;
                    tmp_len += e[j].len;
                }
            }
            if(tmp_val > best_val)  continue;
            double extra = Grham(tmp_len);
            //cout<<"aaaaaa:"<<extra<<endl;
            if(extra >= 0){
                if(tmp_val<best_val){
                    best_val = tmp_val;
                    best_num = n-a.size();
                    best_state = i;
                    best_extra = extra;
                }
                else if(tmp_val==best_val && n-a.size() < best_num){
                    best_num = n-a.size();
                    best_state = i;
                    best_extra = extra;
                }
            }
        }
        printf("Forest %d\nCut these trees:",++cas);
        for(int i = 0 ; i < n ;i++){
            if((1<<i)&best_state)   printf(" %d",i+1);
        }
        printf("\nExtra wood: %.2f\n\n",best_extra);

    }
    return 0;
}


