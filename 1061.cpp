/*青蛙的约会*/
/*这种题以前没见过*/
/*欧几里得算法，注释部分有公式说明*/
#include<iostream>
using namespace std;
#define LLONG long long

LLONG x,y,m,n,L;
//(m*t+x)%L == (n*t+y)%L.   x,y<L
//求最小t.
//(m-n)*t%L = y-x.
//(m-n)*t*+L*k = y-x.
//a*t+b*k = c.

void output();
//求ax+by=gcd(a,b)的特解，以及a,b的最大公约数.
LLONG gcd(int,int,LLONG& ,LLONG&);
int main()
{
    cin >>x >> y>> m >>n >>L;
    output();
    return 0;
}
void output()
{
    long long a= m>n?(m-n):(n-m);
    long long b = L;
    long long c = m>n?(y-x):(x-y);
    //a*t+b*k=gcd(a,b).
    //解为t0,L0
    LLONG t,k;
    //得到公约数和特解
    LLONG d = gcd(a,b,t,k);
    //c%gcd(a,b) != 0无整数解
    if(c%d != 0)
        cout <<"Impossible" <<endl;
    //否则
    else
    {
        //特解带入，下面加入t0是大于零的.
        //a*t0+b*k0=gcd(a,b).
        //同乘c/gcd(a,b)
        //a*t0*c/gcd+b*k0*c/gcd=c.
        //解为t = t0*c/gcd.   k = b*k0*c/gcd.
        //要使t最小，则t0必须变小，k0必须变大.
        //加入t0减小z1,L0增加了z2.那么增加的量必须等于减小的量，a*z1*c/gcd=b*z2*c/gcd.即z1/z2 = (b/gcd)/(a/gcd).
        //t减少b/gcd，则k必须要增加a/gcd.
        //当t减少i个b/gcd时,t = t0*c*gcd-(i+1)*b/gcd < 0且t = t0*c*gcd-i*b/gcd >= 0.此时的t就是最小解.
        //t = t0*c/gcd%(b/gcd).
        t = t*c/d%(b/d);
        //如果t0是小于零的，此时加上一个b/gcd.
        if(t < 0) t += b/d;
        cout <<t <<endl;
    }
}
LLONG gcd(int a,int b,LLONG& t,LLONG& k)
{
    //b = 0.
    //ax+by=ax=gcd(a,0) = a.
    //x =1 ,y = 0.
    if(b == 0)
    {
        t=1;
        k=0;
        return a;
    }
    //b != 0
    //a*x+b*y=gcd(a,b).
    //gcd(a,b) = a*x1+b*y1.
    //gcd(b,a%b) = b*x2+(a%b)*y2.
    //a%b = a-int(a/b)*b
    //a*x1+b*y1=b*x2+(a-int(a/b)*b)*y2.
    //a*x1+b*y1=a*y2+b(x2-int(a/b)*y2)
    //x1 = y2,y1 = x2-int(a/b)*y2.
    LLONG rtn = gcd(b,a%b,t,k);
    LLONG tmp = t;
    t = k;
    k = tmp-a/b*k;
    return rtn;
}
