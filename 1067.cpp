/*取石子游戏*/
/*威佐夫博弈问题+贝蒂定理*/
/*初始为非奇异时，先手胜，反之败*/
/*解方程:1/a+1/b,b=a+1.得a=(sqrt(5)+1)/2*/
/*奇异状态满足([na],[nb])*/
/*即某个时刻若状态(m,n)必须满足[(n-m)a] = ([nb]-[na])a = [na] = m*/
/*则是奇异状态*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#define LLONG long long
int main()
{
    long double a = (sqrt((long double)(5))+1.0)/2.0;
    long long m,n;
    while(cin >>m >>n)
    {
        cout <<(m<n?(m != (LLONG)((n-m)*a)):(n != (LLONG)((m-n)*a))) <<endl;
    }
    return 0;
}
