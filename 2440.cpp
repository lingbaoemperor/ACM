/*DNA*/
/*http://www.cppblog.com/baby-fly/archive/2009/08/17/93643.html*/

#include<iostream>
using namespace std;
#define LOOP 200
int L;
int res[201] = {1,2,4,6,9,0,};
int main()
{
    for(int i=5;i <= LOOP;i++)
        res[i] = (res[i-1]+res[i-3]+res[i-4])%2005;
    while(cin >>L)
        cout <<res[L%LOOP] <<endl;
    return 0;
}
