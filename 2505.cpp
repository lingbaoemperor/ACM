/*A multiplication game*/
/*
因为每一步要走最优，所以当n=
2-9  Stan wins  因为stan先手
9+1-2*9  Ollie wins （2*9）  因为不管Stan 开始乘以几，都不可能超过10
2*9+1-2*9*9 Stan wins （9*2*9） Stan想再赢乘以9
2*9*9+1-2*9*9*2 Ollie wins (2*9*2*9)    Ollie不想让其赢乘以2
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
