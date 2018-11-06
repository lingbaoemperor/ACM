///*Journey*/
///*这个是错的，先放一放*/
///*怎么判断死循环？*/
//#include<iostream>
//#include<vector>
//#include<cstdlib>
//#include<cmath>
//using namespace std;
//
//class Command
//{
//public:
//    int m_iType;
//    int m_iFunction;
//    Command(){}
//    Command(int t,int f){m_iType = t;m_iFunction = f;}
//};
//class Function
//{
//public:
//    vector<Command> m_vCommands;
//    Function(){}
//};
//vector<Function> g_vFunctions;
//
////接受输入
//void input();
//bool dfs(int);
////结果
//int result = 0;
//int x,y,direction;
//bool visit[100] = {false,};
//int main()
//{
//    input();
//    x = y = 0;
//    direction = 1;
//    visit[0] = true;
//    if(dfs(0))
//        cout <<result <<endl;
//    else
//        cout <<"Infinity" <<endl;
//    return 0;
//}
//
//bool dfs(int now)
//{
//    for(int i=0;i < g_vFunctions[now].m_vCommands.size();i++)
//    {
//        int type = g_vFunctions[now].m_vCommands[i].m_iType;
//        int fun = g_vFunctions[now].m_vCommands[i].m_iFunction;
//        switch(type)
//        {
//            //前进
//            case 1:
//                {
//                    if(direction == 1)
//                        x++;
//                    else if(direction == 2)
//                        y++;
//                    else if(direction == 3)
//                        x--;
//                    else if(direction == 4)
//                        y--;
//                    break;
//                }
//            //左转
//            case 2:
//                {
//                    direction = direction%4+1;
//                    break;
//                }
//            //右转
//            case 3:
//                {
//                    direction = (direction+6)%4+1;
//                    break;
//                }
//            //调用其它命令
//            case 4:
//                {
////                    if(visit[fun]) return false;
////                    visit[fun] = true;
//                    if(dfs(fun) == false) return false;
////                    visit[fun] = false;
//                    break;
//                }
//            default:
//                cout <<"Error" <<endl;
//        }
//        if(result < (abs(x)+abs(y)))
//            result = abs(x)+abs(y);
//        cout <<result <<endl;
//    }
//    return true;
//}
//
//void input()
//{
//    int n;
//    cin >>n;
//    for(int i=0;i < n;i++)
//    {
//        int m;
//        Function func;
//        cin >>m;
//        for(int j=0;j < m;j++)
//        {
//            string s;
//            int type;
//            int fun = -1;
//            cin >>s;
//            if(s == "GO")
//                type = 1;
//            else if(s == "LEFT")
//                type = 2;
//            else if(s == "RIGHT")
//                type = 3;
//            else
//            {
//                type = 4;
//                fun = atoi(s.substr(1,s.length()-1).c_str())-1;
//            }
//            func.m_vCommands.push_back(Command(type,fun));
//        }
//        g_vFunctions.push_back(func);
//    }
//}
