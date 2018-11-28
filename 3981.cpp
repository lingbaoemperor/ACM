/*字符串替换*/
//不需要KMP了，很短
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        string res = "";
        int i = 0;
        while(i < s.length())
        {
            if(s.substr(i,3) == "you")
            {
                res.append("we");
                i += 3;
            }
            else
            {
                res.append(s.substr(i,1));
                i += 1;
            }
        }
        cout <<res <<endl;
    }
    return 0;
}
