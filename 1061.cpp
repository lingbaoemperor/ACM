/*���ܵ�Լ��*/
/*��������ǰû����*/
/*ŷ������㷨��ע�Ͳ����й�ʽ˵��*/
#include<iostream>
using namespace std;
#define LLONG long long

LLONG x,y,m,n,L;
//(m*t+x)%L == (n*t+y)%L.   x,y<L
//����Сt.
//(m-n)*t%L = y-x.
//(m-n)*t*+L*k = y-x.
//a*t+b*k = c.

void output();
//��ax+by=gcd(a,b)���ؽ⣬�Լ�a,b�����Լ��.
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
    //��Ϊt0,L0
    LLONG t,k;
    //�õ���Լ�����ؽ�
    LLONG d = gcd(a,b,t,k);
    //c%gcd(a,b) != 0��������
    if(c%d != 0)
        cout <<"Impossible" <<endl;
    //����
    else
    {
        //�ؽ���룬�������t0�Ǵ������.
        //a*t0+b*k0=gcd(a,b).
        //ͬ��c/gcd(a,b)
        //a*t0*c/gcd+b*k0*c/gcd=c.
        //��Ϊt = t0*c/gcd.   k = b*k0*c/gcd.
        //Ҫʹt��С����t0�����С��k0������.
        //����t0��Сz1,L0������z2.��ô���ӵ���������ڼ�С������a*z1*c/gcd=b*z2*c/gcd.��z1/z2 = (b/gcd)/(a/gcd).
        //t����b/gcd����k����Ҫ����a/gcd.
        //��t����i��b/gcdʱ,t = t0*c*gcd-(i+1)*b/gcd < 0��t = t0*c*gcd-i*b/gcd >= 0.��ʱ��t������С��.
        //t = t0*c/gcd%(b/gcd).
        t = t*c/d%(b/d);
        //���t0��С����ģ���ʱ����һ��b/gcd.
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
