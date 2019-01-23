/*Integer Intervals*/
/*
"finds the minimal number of elements in a set containing at least two different integers from each interval."
这个题意真难理解，
求一个集合，这个集合满足：每个interval最少包含2个集合中的数. 求这个集合最少有多少元素.
差分约束：
s[x]代表[0,x)区间的元素在所求集合中个数，(不能是[0,x])
s[b+1]-s[a] >= 2
s[i+1]-s[i] >= 0
s[i+1]-s[i] <= 1
即
s[a]-s[b+1] <= -2
s[i]-s[i+1] <= 0
s[i+1]-s[i] <= 1

s[x] x属于任何一个区间
MAX+1为源点，每必要再另外添加源点了，会超时

求s[MAX+1] - s[Min]
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_LIMIT 10005
#define MAX_EDGE 50005
int g_iN;
int g_iMax;
int g_iMin;

class Edge
{
public:
    int m_iNow;
    int m_iNext;
    int m_iWeight;
    Edge(){}
    Edge(int now,int next,int weight)
    {
        m_iNow = now;
        m_iNext = next;
        m_iWeight = weight;
    }
};


int g_iCount = 0;
vector<Edge> g_eEdges;
vector<int> g_vHead[MAX_LIMIT];

//SPFA
bool visit[MAX_LIMIT] = {false,};

void input();
void add_edge(int,int,int);

//超时
void BellMan();
//
void SPFA();

int main()
{
    input();
    SPFA();
    return 0;
}
void input()
{
    cin >>g_iN;
    g_iMax = -1;
    g_iMin = 0x7fffffff;
    for(int i=0;i < g_iN;i++)
    {
        int a,b;
        cin >>a >>b;
        g_iMax = g_iMax>b?g_iMax:b;
        g_iMin = g_iMin<a?g_iMin:a;
        //
        add_edge(b+1,a,-2);
    }
    //
    for(int j=g_iMin;j <= g_iMax;j++)
    {
        add_edge(j+1,j,0);
        add_edge(j,j+1,1);
    }
}
void SPFA()
{
    int dis[MAX_LIMIT] = {0,};
    memset(dis,0x7f,4*(g_iMax+2));
    dis[g_iMax+1] = 0;

    queue<int> q;
    q.push(g_iMax+1);
    memset(visit,false,g_iMax+2);
    visit[g_iMax+1] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        visit[u] = false;
        for(int i=0;i < g_vHead[u].size();i++)
        {
            int eindex = g_vHead[u][i];
            int v = g_eEdges[eindex].m_iNext;
            int w = g_eEdges[eindex].m_iWeight;
            if(dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                if(!visit[v])
                {
                    q.push(v);
                    visit[v] = true;
                }
            }
        }
    }
    cout <<dis[g_iMax+1] - dis[g_iMin] <<endl;
}
//超时
void BellMan()
{
    int dis[MAX_LIMIT] = {0,};
    memset(dis,0x7f,4*(g_iMax+2));
    dis[g_iMax+1] = 0;

    //一共g_iMax - g_iMin + 2个顶点
    for(int k=g_iMin;k <= g_iMax;k++)
    {
        for(int i=0;i < g_eEdges.size();i++)
        {
            int src = g_eEdges[i].m_iNow;
            int dst = g_eEdges[i].m_iNext;
            int weight = g_eEdges[i].m_iWeight;
            if(dis[dst] > dis[src]+weight)
                dis[dst] = dis[src]+weight;
        }
    }
    cout <<dis[g_iMax+1] - dis[g_iMin] <<endl;
}
void add_edge(int src,int dst,int weight)
{
    g_eEdges.push_back(Edge(src,dst,weight));
    g_vHead[src].push_back(g_iCount);
    g_iCount++;
}
