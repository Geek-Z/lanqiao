#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
double a,b,c,d;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    double x,x1,x2,xx;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    // 分为100个长度为1的小区间
    for (x=-100;x<=100;x+=1)
    { 
        x1=x;x2=x+1;
        if (f(x1)==0) printf("%.2f ",x1);
        // 如果两个当中存在值的情况, 则采用二分的办法。
        else if (f(x1)*f(x2)<0)
        {
            while (x2-x1>=0.001)
            {
                xx=(x1+x2)/2;
                if ((f(x1)*f(xx))<=0)
                    x2=xx;
                else x1=xx;
            }
            printf("%.2f ",x1);
        }
    }
}