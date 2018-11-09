/*Card Trick*/
/*
最终结果是
1、2、3、...、n.
当只有当最后一张n时，出入对n次，然后拿出n.
当只有n-1和n时，出入对n-1次，然后拿出n-1.
...
当1、...、n.都未取出，出入对1次，然后拿出1.

反过来，
q1保存取出n时的状态
n-1入队q2，q1入队q2，此时q2是取出n-1时的状态，q2出入q2.size()-(n-1)%q2.size()次是还未将n-1张牌放入末端的状态
依此类推...
1入队q2，q1入队q2，此时q2时取出1时的状态，q2出入q2.size()-1%q2.size()即n-1次是最初状态

这样时间好像太长了
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
