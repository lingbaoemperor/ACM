/*Automated Telephone Exchange*/
#include<iostream>
using namespace std;

int N;
int result();
int main()
{
    cin >>N;
    cout <<result();
    return 0;
}
int result()
{
    int r = 0;
    for(int i=0;i <= 99;i++)
        for(int j=0;j <= 99;j++)
            if(N-i-j == 0)
                r++;
    return r;
}
