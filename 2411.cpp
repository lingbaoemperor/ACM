/*瓷砖覆盖*/
/*DP[i][j]代表第i行第j个状态的所有可能结果
j的范围从0到2^W-1
每到一个j,判断从之前一行的每个可以到[i][j]的状态D[i-1][k]的总和

这题测试数据不太严谨，把判断条件换个顺序就超时了
*/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define SWAP(x,y) (y = ((x+y)-(x=y)))

int H,W;
void output();
bool compatablity(int,int);
long long dp[12][2048] = {0,};
int main()
{
    while(cin >>H >>W)
    {
        if(H == 0) break;
        //如果面积是奇数，肯定不能放
        if((H%2 != 0) && (W%2 != 0)) {cout <<0 <<endl; continue;}
        if(H < W) swap(H,W);
        output();
    }
    return 0;
}

bool compatablity(int i,int k)
{
    //上下两行是否兼容
    int x = 0;
    while(x < W)
    {
        //假如该行的某一位是0
        if((i&(0x1 << x)) == 0)
        {
            //那么上一行的该位一定是1，因为如果是0，说明2个竖着放的砖的第一格，竖直着连在一起了，不可能
            if((k&(0x1 << x)) == 0)
                return false;
            //是0，不可能
            else
                x++;
        }
        //假如该行的某一位是1
        else
        {
             //是0，（当前行的该位是竖着的砖的第二部分），直接检查看下一位
            if((k&(0x1 << x)) == 0)
                x += 1;
            //那么上一行如果是1，（当前行的当前位一定是横着放的砖的第一部分）
            else
            {
                //上一行是1，那么该行的下一位一定是1，上一行的下一位也是1

                //如果已经是最后一位，就没有下一位了

                //都是1
                if((i&(0x1 << (x+1))) && (k&(0x1 << (x+1))) &&(x != W-1))
                        x += 2;
                else
                    return false;
            }
        }
    }
    return true;
}

void output()
{
    int w = (1 << W)-1;
    memset(dp,0,sizeof(dp));
    //对于第一行的某个状态来说，只可能有一种摆放情况
    //假如是0，说明第一行全部是竖直摆放的
    for(int j=0;j <= w;j++)
    {
        //检查是否能达到每个状态，不能到达的状态有0种摆放情况
        int x = 0;
        int res = 1;
        while(x < W)
        {
            //某一位是1，下一位一定是1
            if(j&(0x1 << x))
            {
                //如果这个1已经是最后一位，或者，下一个是0，说明不能到达这个状态
                if((x == W-1) || ((j&(0x1 << (x+1))) == 0))
                {
                    res = 0;
                    break;
                }
                //判断2个1后面的位置
                x += 2;
            }
            //某一位是0,下一位可以是0，也可以是1
            else
                //否则判断下一位
                x += 1;
        }
        dp[1][j] = res;
    }
//    for(int i=0;i <= w;i++)`
//        cout <<dp[1][i] <<" ";
    //第一行完成后，从第二行开始，检查每行的某个状态
    for(int i=2;i <= H;i++)
    {
        //对于每个状态来说，能到达改状态的摆放方式总数，即前一行所有能到达该状态的状态的摆放方式的总和
        for(int j=0;j <= w;j++)
        {
            for(int k=0;k <= w;k++)
            {
                if(compatablity(j,k))
                    dp[i][j] += dp[i-1][k];
            }
        }
    }
    cout <<dp[H][w] <<endl;
}
