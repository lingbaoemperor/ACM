/*Chess*/
/*动态规划*/

#include<iostream>
#include<cstring>
using namespace std;
#define MAX 1001

int N = 0;
//输入
int players[MAX][2] = {0,};
int dp[MAX][16][16] = {0,};

void DP();
int main()
{
    N = 1;
    while(cin >>players[N][0] >>players[N][1])
    {
        N++;
    }
    DP();
    cout <<dp[N-1][15][15] <<endl;
    return 0;
}
void DP()
{
    memset(dp,0,4*MAX*16*16);
    //dp[i][j][k] = 0
    //dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k],dp[i-1][j-1][k]+player[i][0],dp[i-1][j][k-1]+player[i][1])
    for(int i=1;i < N;i++)
    {
        for(int j=0;j <= 15;j++)
        {
            for(int k=0;k <= 15;k++)
            {
                if(j)   dp[i][j][k] = max(dp[i][j][k],max(dp[i-1][j][k],dp[i-1][j-1][k]+players[i][0]));
                if(k)   dp[i][j][k] = max(dp[i][j][k],max(dp[i-1][j][k],dp[i-1][j][k-1]+players[i][1]));
            }
        }
    }
}
