/*Factorial*/

/*����������5�ĸ���
n/5Ϊ����1��...��n��5�ı����ĸ���*
n/25Ϊ����1��...��n��25�ı����ĸ���
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
