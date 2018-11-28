///*The Lucky Numbers*/
///*
//从与输入数字等长的最小lucky number开始深搜
//例如输入1234567，从4444444开始搜索,知道最大值的地方
//..........别看这个了，超时了不想写注释了
//*/
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//
//bool isInRange(string s);
//void dfs(int);
////测试用例数
//int T;
////起始和结束
//string g_sBegin,g_sOver;
////搜索多少位数
//int g_iLen;
////深搜过程中的数字
//string g_sDfs = "";
//
//int result = 0;
//int main()
//{
//    cin >>T;
//    while(T)
//    {
//        //初始索引为g_sBegin.length()-1
//        //比如[50 100],搜索十进制数位数范围是2
//        cin >>g_sBegin >>g_sOver;
//        g_iLen = g_sOver.length();
//        for(int i=0;i < g_sBegin.length()-1;i++)
//            g_sDfs.append("4");
//        result = 0;
//        dfs(g_sBegin.length()-1);
//        T--;
//        cout <<result <<endl;
//    }
//    return 0;
//}
//
//void dfs(int i)
//{
//    if(i > g_iLen) return;
//    //如果再范围内
//    if(isInRange(g_sDfs))
//    {
//        result++;
//        string s = g_sDfs;
//        reverse(s.begin(),s.end());
//        //如果反转的数字不在范围内
//        if(!isInRange(s))
//            result++;
//    }
//    //下一位填4
//    g_sDfs.append("4");
//    dfs(i+1);
//    g_sDfs = g_sDfs.substr(0,g_sDfs.length()-1);
//    //下一位填7
//    g_sDfs.append("7");
//    dfs(i+1);
//    g_sDfs = g_sDfs.substr(0,g_sDfs.length()-1);
//}
//
//bool isInRange(string s)
//{
//    //小于等于最大值
//    if(s.length() > g_sOver.length() || s.length() < g_sBegin.length()) return false;
//    if(s.length() < g_sOver.length() && s.length() > g_sBegin.length()) return true;
//    if(s.length() == g_sBegin.length())
//    {
//        //大于等于最小值
//        for(int i=0;i < s.length();i++)
//        {
//            if(s[i] > g_sBegin[i])
//                break;
//            else if(s[i] == g_sBegin[i])
//                continue;
//            else
//                return false;
//        }
//        //后边界长度大于前边界
//        if(g_sOver.length() > g_sBegin.length()) return true;
//        //边界长度相等
//        else
//        {
//            //小于等于后边界
//            for(int i=0;i < s.length();i++)
//            {
//                if(s[i] < g_sOver[i])
//                    return true;
//                else if(s[i] == g_sOver[i])
//                    continue;
//                else
//                    return false;
//            }
//            return true;
//        }
//    }
//    //前长度一定小于后边界
//    else if(s.length() == g_sOver.length())
//    {
//        //小于等于后边界
//        for(int i=0;i < s.length();i++)
//        {
//            if(s[i] < g_sOver[i])
//                return true;
//            else if(s[i] == g_sOver[i])
//                continue;
//            else
//                return false;
//        }
//        return true;
//        //前边界长度一定小于后边界
//    }
//    return false;
//}
