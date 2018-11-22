/*P,MTHBGWB*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,string> g_mTable;
int g_iN = 1;

void create_table();
string find_by_alpha(string);
string find_by_symbol(string);
void decode(string);
int main()
{
    string s;
    int N;
    cin >>N;
    create_table();
    for(;g_iN <= N;g_iN++)
    {
        cin >>s;
        decode(s);
    }
    return 0;
}

void create_table()
{
    g_mTable["A"] = ".-";g_mTable["B"] = "-...";g_mTable["C"] = "-.-.";g_mTable["D"] = "-..";g_mTable["E"] = ".";g_mTable["F"] = "..-.";
    g_mTable["G"] = "--.";g_mTable["H"] = "....";g_mTable["I"] = "..";g_mTable["J"] = ".---";g_mTable["K"] = "-.-";g_mTable["L"] = ".-..";
    g_mTable["M"] = "--";g_mTable["N"] = "-.";g_mTable["O"] = "---";g_mTable["P"] = ".--.";g_mTable["Q"] = "--.-";g_mTable["R"] = ".-.";
    g_mTable["S"] = "...";g_mTable["T"] = "-";g_mTable["U"] = "..-";g_mTable["V"] = "...-";g_mTable["W"] = ".--";g_mTable["X"] = "-..-";
    g_mTable["Y"] = "-.--";g_mTable["Z"] = "--..";g_mTable["_"] = "..--";g_mTable[","] = ".-.-";g_mTable["."] = "---.";g_mTable["?"] = "----";
}

void decode(string input)
{
    string res = "";
    int i = 0;
    int slen[100] = {0,};
    for(;i < input.length();i++)
    {
        string subs = find_by_alpha(input.substr(i,1));
        res.append(subs);
        slen[i] = subs.length();
    }
    i--;
    string result = "";
    for(int start = 0;i >= 0;start+=slen[i],i--)
    {
        string s = find_by_symbol(res.substr(start,slen[i]));
        result.append(s);
    }
    cout <<g_iN <<": " <<result <<endl;
}

string find_by_alpha(string key)
{
    map<string,string>::iterator it;
    it = g_mTable.find(key);
    return (string)(it ->second);
}
string find_by_symbol(string value)
{
    for(map<string,string>::iterator it=g_mTable.begin();it != g_mTable.end();it++)
    {
        if(it ->second == value)
            return (string)(it ->first);
    }
    return "";
}
