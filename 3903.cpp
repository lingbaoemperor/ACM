/*Stock Exchange*/

/*DP*/
/*����������У����ַ�*/
#include<iostream>
#include<cstring>
using namespace std;
int N;
long long prices[100001] = {0,};
void DP();
int main()
{
    while(cin >>N)
    {
        for(int i=0;i < N;i++) cin >>prices[i];
        DP();
    }
    return 0;
}

void DP()
{
    //���ڶ��ֲ���
    long long record[100001] = {0,};
    int len = 1;
    //���˱���ÿ�����֣���ջ�������ջ��С�Ķ��ֲ���Ҫ�滻��λ�ã���ջ�׿�ʼ��һ�����ڵ�������Ԫ�ص�λ�ã�
    //5 2 1 4 5 3
    //record:
    //5��ջ
    //2 �滻 5  ->  2
    //1�滻2 -> 1
    //4��ջ ->1 4
    //5��ջ -> 1 4 5
    //3�滻4 -> 1 3 4
    record[0] = prices[0];
    for(int i=1;i < N;i++)
    {
        if(prices[i] > record[len-1])
        {
            record[len] = prices[i];
            len++;
        }
        else
        {
            int l=0,r=len-1;
            int m;
            while(l != r)
            {
                m = (l+r)/2;
                if(record[m] < prices[i])
                    l = m+1;
                else
                    r = m;
            }
            record[r] = prices[i];
        }
    }
    cout <<len <<endl;
}
