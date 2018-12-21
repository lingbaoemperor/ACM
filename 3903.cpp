/*Stock Exchange*/

/*DP*/
/*最长升序子序列，二分法*/
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
    //用于二分查找
    long long record[100001] = {0,};
    int len = 1;
    //依此遍历每个数字，比栈顶大的入栈，小的二分查找要替换的位置（从栈底开始第一个大于等于它的元素的位置）
    //5 2 1 4 5 3
    //record:
    //5入栈
    //2 替换 5  ->  2
    //1替换2 -> 1
    //4入栈 ->1 4
    //5入栈 -> 1 4 5
    //3替换4 -> 1 3 4
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
