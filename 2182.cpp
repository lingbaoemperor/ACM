/*Lost Cows*/
/*
例如最后一头牛是前面比编号它大的牛的个数为n，
该牛的编号为n+1，
以此类推再寻找第二头牛的编号
（不用线段树也没关系，时间足够）
*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 8001
//输入
int N;
int cows[MAX] = {0,};
//标记牛是否访问过
int number[MAX] = {0,};
//结果
int result[MAX] = {0,};
void output();
int seq_search(int);
int main()
{
    cin >>N;
    output();
    return 0;
}

void output()
{
    memset(number,0,4*MAX);
    for(int i=2;i <= N;i++)
        cin >>cows[i];
    cows[1] = 0;
    for(int i=N;i > 0;i--)
    {
        int num = seq_search(cows[i]+1);
        result[i] = num;
        number[num] = 1;
    }
//    cout <<endl;
    for(int i=1;i <= N;i++)
        cout <<result[i] <<endl;
}

int seq_search(int x)
{
    int rt = 1;
    for(int i=1;i <= N;i++)
    {
        if(number[i] == 1)
            continue;
        if(rt != x)
            rt++;
        else
            return i;
    }
    return -1;
}
