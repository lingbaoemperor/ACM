/*Factorial*/

/*乘数因子中5的个数
n/5为因子1、...、n中5的倍数的个数*
n/25为因子1、...、n中25的倍数的个数
...
*/

#include<iostream>

using namespace std;

int main()
{
    int T;
    cin >>T;
    while(T)
    {
        int result = 0;
        long long N;
        cin >>N;
        while(N)
        {
            result += N/5;
            N = N/5;
        }
        T--;
        cout <<result <<endl;
    }
    return 0;
}
