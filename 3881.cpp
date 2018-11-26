/*Happy Telephones*/
/*ºÚµ•Ã‚*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    while(true)
    {
        int N,M;
        cin >>N >>M;
        if(M == 0) break;
        vector<int> start;
        vector<int> duration;
        for(int i=0;i < N;i++)
        {
            int s,d;
            cin >>s >>d;
            cin >>s >>d;
            start.push_back(s);
            duration.push_back(d);
        }
        for(int i=0;i < M;i++)
        {
            int s,d;
            int sum = 0;
            cin >>s >>d;
            for(int j=0;j < N;j++)
            {
                if(s >= (start[j]+duration[j]))
                    continue;
                if((s+d) <= start[j])
                    continue;
                    sum++;
            }
            cout <<sum <<endl;
        }
    }
    return 0;
}
