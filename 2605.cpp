/*Simple game on a grid*/
/*
m=1,n-[n/2]
n=1,m-[m/2]
m,n>=2��m��n����һ����3�ı���,2
m,n>=2��m��n��3�ı���,1
Դ������-ǳ̸���̵ķָ�˼��
*/
#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin >>m >>n;
    if(m == 1) cout <<n-n/2 <<endl;
    else if(n == 1) cout <<m-m/2 <<endl;
    else if(m%3 == 0 || n%3 == 0) cout <<2 <<endl;
    else cout <<1 <<endl;
    return 0;
}
