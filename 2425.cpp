/*A Chess Game*/
/*SG������Nim��Ϸ��ֻ��Ҫ֪�����۾�OK��*/

#include<iostream>
#include<vector>
#include <algorithm>
#include<cstring>

using namespace std;
#define MAX 1005

vector<int> g_vGraph[MAX];

int g_vGx[MAX] = {0,};
int dfs(int);
int main()
{
    int N;
    while(cin >>N)
    {
        for(int i=0;i < N;i++)
        {
            int n,next;
            cin >>n;
            g_vGraph[i].clear();
            for(int j=0;j < n;j++)
            {
                cin >>next;
                g_vGraph[i].push_back(next);
            }
        }
        memset(g_vGx,-1,sizeof(g_vGx));
        int M;
        while(cin >>M)
        {
            int result = 0;
            if(M == 0)  break;
            //����
            int chess;
            for(int i=0;i < M;i++)
            {
                cin >>chess;
                //���
                result ^= dfs(chess);
            }
            if(result == 0)
                cout <<"LOSE" <<endl;
            else
                cout <<"WIN" <<endl;
        }
    }
    return 0;
}

int dfs(int x)
{
    //�ѹ��Ĳ�������
    if(g_vGx[x] != -1) return g_vGx[x];
    char vMex[MAX] = {0,};
    memset(vMex,0,sizeof(vMex));
    for(int i=0;i < g_vGraph[x].size();i++)
    {
        //��̵�gx
        int res = dfs(g_vGraph[x][i]);
        vMex[res] = 1;
    }
    //����mex����ȥȡֵ�����ڼ����е���Сֵ
    int i = 0;
    for(;vMex[i];i++){}
    g_vGx[x] = i;
    return g_vGx[x];
}
