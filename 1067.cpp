/*ȡʯ����Ϸ*/
/*������������+���ٶ���*/
/*��ʼΪ������ʱ������ʤ����֮��*/
/*�ⷽ��:1/a+1/b,b=a+1.��a=(sqrt(5)+1)/2*/
/*����״̬����([na],[nb])*/
/*��ĳ��ʱ����״̬(m,n)��������[(n-m)a] = ([nb]-[na])a = [na] = m*/
/*��������״̬*/
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
