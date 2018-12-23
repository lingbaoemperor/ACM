/*√‘π¨Œ Ã‚*/

#include<iostream>
#include<vector>
using namespace std;

class Pos
{
public:
    int x,y;
    Pos(){}
    Pos(int r,int c){x = r; y = c;}
};
int mp[5][5] = {0,};
vector<Pos> g_vResult;
vector<Pos> g_vTmp;
bool visit[5][5] = {false,};
void dfs(int,int);
int main()
{
    for(int i=0;i < 5;i++)
        for(int j=0;j < 5;j++)
            cin >>mp[i][j];
    dfs(0,0);
    for(int i=0;i < g_vResult.size();i++)
        cout <<"(" <<g_vResult[i].x <<", " <<g_vResult[i].y <<")" <<endl;
    return 0;
}
void dfs(int x,int y)
{
    if(x >= 5 || y >= 5 || x < 0 || y < 0) return;
    if(mp[x][y] == 1) return;
    if(visit[x][y]) return;
    visit[x][y] = true;
    g_vTmp.push_back(Pos(x,y));
    //÷’µ„
    if(x == 4 && y == 4)
    {
        if(g_vTmp.size() > g_vResult.size())
            g_vResult = g_vTmp;
    }
    dfs(x+1,y);
    dfs(x,y+1);
    g_vTmp.pop_back();
    visit[x][y] = false;
}
