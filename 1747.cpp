/*Expression*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

/*
Ex0:((A0|B0)|(A0|B0))
Ex1:((A1|B1)|(Ex0|((A1|A1)|(B1|B1))))
Ex2:((A2|B2)|(Ex1|((A2|A2)|(B2|B2))))
...
*/

string g_sExpression = "((A0|B0)|(A0|B0))";
int g_iN;
void output(int);
int main()
{
    cin >>g_iN;
    output(1);
    cout <<g_sExpression;
    return 0;
}

void output(int i)
{
    if(i == g_iN) return;
    string s = g_sExpression;
    char c_s[10] = {0,};
    sprintf(c_s,"%d",i);
    string s_num = c_s;
    g_sExpression = "((A"+s_num+"|B"+s_num+")|("+s+"|((A"+s_num+"|A"+s_num+")|(B"+s_num+"|B"+s_num+"))))";
    output(i+1);
}
