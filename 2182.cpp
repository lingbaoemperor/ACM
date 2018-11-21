/*Lost Cows*/
/*
�������һͷţ��ǰ��ȱ�������ţ�ĸ���Ϊn��
��ţ�ı��Ϊn+1��
�Դ�������Ѱ�ҵڶ�ͷţ�ı��
�������߶���Ҳû��ϵ��ʱ���㹻��
*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 8001
//����
int N;
int cows[MAX] = {0,};
//���ţ�Ƿ���ʹ�
int number[MAX] = {0,};
//���
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
