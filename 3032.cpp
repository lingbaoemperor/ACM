/*Card Trick*/
/*
���ս����
1��2��3��...��n.
��ֻ�е����һ��nʱ�������n�Σ�Ȼ���ó�n.
��ֻ��n-1��nʱ�������n-1�Σ�Ȼ���ó�n-1.
...
��1��...��n.��δȡ���������1�Σ�Ȼ���ó�1.

��������
q1����ȡ��nʱ��״̬
n-1���q2��q1���q2����ʱq2��ȡ��n-1ʱ��״̬��q2����q2.size()-(n-1)%q2.size()���ǻ�δ��n-1���Ʒ���ĩ�˵�״̬
��������...
1���q2��q1���q2����ʱq2ʱȡ��1ʱ��״̬��q2����q2.size()-1%q2.size()��n-1�������״̬

����ʱ�����̫����
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
void output();
int main()
{
    int n;
    cin >>n;
    while(n > 0)
    {
        cin >>N;
        output();
        n--;
    }
    return 0;
}

void output()
{
    queue<int> q1,q2;
    q2.push(N);
    for(int i1=N-1;i1 > 0;i1--)
    {
        q1 = q2;
        queue<int> q;
        q2 = q;
        q2.push(i1);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        int sz = q2.size();
        for(int i2=sz-i1%sz;i2 > 0;i2--)
        {
            int top = q2.front();
            q2.pop();
            q2.push(top);
        }
    }
    while(!q2.empty())
    {
        cout<< q2.front() <<" ";
        q2.pop();
    }
    cout <<endl;
}
