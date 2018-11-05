/*Bode Plot*/
/*»¯¼ò¹«Ê½*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double Vs,R,C,w;
    int N;
    cin >>Vs >>R >>C >>N;
    while(N > 0)
    {
        N--;
        cin >>w;
        double result = Vs*R*C*w/sqrt(1.0+pow(w,2)*pow(C,2)*pow(R,2));
        cout <<setiosflags(ios::fixed) << setprecision(3) <<result <<endl;
    }
    return 0;
}
