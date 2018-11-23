/*Life Line*/
/*
广搜一波， 其实用不着这么复杂，太久没碰了
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_NODE 56

//输入
int N,C;
void input();
int bfs(int);
int get_score();

int g_iNode = 0;
//访问标记
int visit[MAX_NODE] = {0,};
//每个位置的玩家
int g_iPlayer[MAX_NODE] = {0,};
vector<int> g_vGraphic[MAX_NODE];

vector<int> g_vResult;
int main()
{
    while(true)
    {
        g_iNode = 0;
        memset(g_iPlayer,0,MAX_NODE*4);
        memset(g_vGraphic,0,MAX_NODE*4);
        cin >>N >>C;
        if(N ==0 && C == 0) break;
        input();
        g_vResult.push_back(get_score());
    }
    for(int i=0;i < g_vResult.size();i++)
        cout <<g_vResult[i] <<endl;
    return 0;
}
int get_score()
{
    int result = -0xfffff;
    //遍历每个可落子的点
    for(int i=1;i <= g_iNode;i++)
    {
        memset(visit,0,56*4);
        if(g_iPlayer[i] != 0) continue;
        g_iPlayer[i] = C;
        //从每个与落子点相邻的点开始搜索，保存该次落子的分数总和
        int score = 0;
        for(int j=0;j < g_vGraphic[i].size();j++)
        {
            int tmp = 0;
            int neighbor = g_vGraphic[i][j];
            if(g_iPlayer[neighbor] == 0 || visit[neighbor])
                continue;
            //一次搜寻结果
            tmp = bfs(neighbor);
            score += (g_iPlayer[neighbor] == C?(-tmp):tmp);
        }
        if(!visit[i])
        {
            int tmp = bfs(i);
            score -= tmp;
        }
        g_iPlayer[i] = 0;
        result = result<score?score:result;
    }
    return result;
}
//从某个位置开始搜索，如果有空位返回0
int bfs(int s)
{
    //有空位置，没分
    int score = 1;
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    int c = g_iPlayer[s];
    //有空位退出
    bool flag = true;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0;i < g_vGraphic[now].size();i++)
        {
            int x = g_vGraphic[now][i];
            if(g_iPlayer[x] == 0)
            {
                flag = false;
                continue;
            }
            if(!visit[x] && g_iPlayer[x] == c)
            {
                visit[x] = 1;
                score++;
                q.push(x);
            }
        }
    }
    if(flag == false) return 0;
    return score;
}

//建图
void input()
{
    for(int i=1;i <= N;i++)
    {
        for(int j=1;j <= i;j++)
        {
            g_iNode++;
            if(i != N)
            {
                g_vGraphic[g_iNode].push_back(g_iNode+i);
                g_vGraphic[g_iNode+i].push_back(g_iNode);
                g_vGraphic[g_iNode].push_back(g_iNode+i+1);
                g_vGraphic[g_iNode+i+1].push_back(g_iNode);
            }
            if(j != i)
            {
                g_vGraphic[g_iNode].push_back(g_iNode+1);
                g_vGraphic[g_iNode+1].push_back(g_iNode);
            }
        }
    }
    for(int i=1;i <= g_iNode;i++)
        cin >>g_iPlayer[i];
}
