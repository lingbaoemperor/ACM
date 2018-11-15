/*A Simple Question of Chemistry*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float p,n;
    cin >>p;
    while(cin >>n)
    {
        if(n == 999)
        {
            cout <<"End of Output" <<endl;
            break;
        }
        cout <<setiosflags(ios::fixed) <<setprecision(2) <<n-p <<endl;
        p = n;
    }
    return 0;
}
