/*A multiplication game*/
/*
��Ϊÿһ��Ҫ�����ţ����Ե�n=
2-9  Stan wins  ��Ϊstan����
9+1-2*9  Ollie wins ��2*9��  ��Ϊ����Stan ��ʼ���Լ����������ܳ���10
2*9+1-2*9*9 Stan wins ��9*2*9�� Stan����Ӯ����9
2*9*9+1-2*9*9*2 Ollie wins (2*9*2*9)    Ollie��������Ӯ����2
                    .
                    .
                    .
*/
#include<iostream>
using namespace std;

int main()
{
    long double n;
    while(cin>>n)
    {
        while(n > 18) n=n/18;
        if(n > 9)
            cout <<"Ollie wins." <<endl;
        else if(n <= 9)
            cout <<"Stan wins." <<endl;
    }
    return 0;
}
