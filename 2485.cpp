/*Highways*/
/*��С������*/

#include<iostream>
#include<cstring>
using namespace std;
#define MAX_N 501
#define INF 0x7fffffff

int T,N;
int g_iGraphic[MAX_N][MAX_N];

void input();
void Prim();
int main()
{
    cin >>T;
    while(T)
    {
        T--;
        input();
        Prim();
    }
    return 0;
}
void Prim()
{
    //���ս��
    int result = -1;

    //ÿ��������v���������ߵ���СȨֵ
    int cost[MAX_N] = {INF,};
    memset(cost,0x7f,sizeof(cost));
    //v�����еĵ�
    bool visit[MAX_N] = {false,};
    int v = 1;
    visit[v] = true;
    cost[v] = 0;

    //����N-1����
    for(int i=1;i < N;i++)
    {
        int v_add = -1;
        int mincost = INF;
        //���¶��㵽v���ϵ���̾���
        for(int j=1;j <= N;j++)
        {
            if(visit[j]) continue;
            if(cost[j] > g_iGraphic[v][j])
                cost[j] = g_iGraphic[v][j];
            if(cost[j] < mincost)
            {
                mincost = cost[j];
                v_add = j;
            }
        }
        v = v_add;
        visit[v] = true;
        if(result < mincost)
            result = mincost;
    }
    cout <<result <<endl;
}
void input()
{
    cin >>N;
    for(int i=1;i <= N;i++)
    {
        for(int j=1;j <= N;j++)
            cin >>g_iGraphic[i][j];
    }
}
