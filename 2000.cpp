/*Gold Coins*/
#include<iostream>
using namespace std;

int howmany();
int N;
int main()
{
    while(cin >>N)
    {
        if(N == 0) break;
        cout <<N <<" " <<howmany() <<endl;
    }
    return 0;
}
int howmany()
{
    int sum = 0;
    int days = 0;
    int i = 1;
    bool flag = true;
    while(flag)
    {
        for(int j=1;j <= i;j++)
        {
            if(days == N)
            {
                flag = false;
                break;
            }
            days++;
            sum += i;
        }
        i++;
    }
    return sum;
}
