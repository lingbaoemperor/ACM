/*So you want to be a 2n-aire?*/

/*
这个有点复杂，网上有解析
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

int N;
double t;
double e[31] = {0,};
int main()
{
    while(cin >>N >>t)
    {
        if(N == 0) break;
        memset(e,0,31*sizeof(double));
        e[N] = pow((double)2,N);
        for(int i=N-1;i >= 0;i--)
        {
            double p = pow((double)2,i)/e[i+1];
            if(p <= t)
                e[i] = (1+t)/2*e[i+1];
            else
                e[i] = (p-t)/(1-t)*pow((double)2,i)+(1-p)/(1-t)*(1+p)/2*e[i+1];
        }
        cout <<setiosflags(ios::fixed) <<setprecision(3) <<e[0] <<endl;
    }
    return 0;
}
