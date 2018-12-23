/*Duplicate Removal*/
#include <iostream>
using namespace std;

int main()
{
    int N;
    int input[10000];
    while(cin >>N)
    {
        if(N == 0) break;
        for(int i=0;i < N;i++)
            cin >>input[i];
        int duplication = -1;
        for(int i=0;i < N;i++)
        {
            if(input[i] != duplication)
            {
                duplication = input[i];
                cout <<input[i] <<" ";
            }
        }
        cout <<"$" <<endl;
    }
    return 0;
}
