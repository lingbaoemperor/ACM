/*Maya Calendar*/
#include <iostream>
#include<vector>
#include<string>
#include <cstdlib>
using namespace std;
//Habb: 18months 20days + 1month 5days
//month string. day 0-19/4
//Tzolkin: 13month 20days
//month 1-13. day string

//day.month year

string Haab_Month[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",\
                        "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string Tzolkin_Day[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",\
                            "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

class Date
{
public:
    int day;
    int month;
    int year;
    Date(){}
    Date(int d,int m ,int y){day = d;month = m;year = y;}
};
int N;
vector<Date> g_vDate;
void input();
void output();
int main()
{
    input();
    output();
    return 0;
}
void input()
{
    cin >>N;
    for(int i=0;i < N;i++)
    {
        string day,month;
        int year;
        cin >>day >>month >>year;
        //找到month是那一个月
        int j=0;
        for(;Haab_Month[j] != month;j++){}
        g_vDate.push_back(Date(atoi(day.substr(0,day.length()-1).c_str()),j,year));
    }

}
void output()
{
    cout <<N <<endl;
    for(int i=0;i < g_vDate.size();i++)
    {
        //计算总天数
        Date date = g_vDate[i];
        int sum = 0;
        sum += date.year*365;
        sum += date.month*20;
        sum += date.day;

        //计算年月日
        int year = sum/(13*20);
        int month = sum%(13*20)%13+1;
        int day = sum%(13*20)%20;
        int j=0;
        for(;Tzolkin_Day[j] != Tzolkin_Day[day];j++){}
        cout <<month <<" " <<Tzolkin_Day[j] <<" " <<year <<endl;
    }
}
