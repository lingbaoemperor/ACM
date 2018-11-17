/*Silver Matrix*/
/*
S1 S2
S3 S4
S1 一定等于 S4
S2 为 S1+n,n为当前矩阵的长,n*n
S3中的对角线上的元素等于S2中对角线上元素减一,其它元素于S2相同
*/
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 513

int matrix[MAX][MAX] = {0,};

int K;

void DAC(int);
int main()
{
    cin >>K;
    int N = (int)pow((float)2,(float)K);
    DAC(N);
    for(int i=1;i <= N;i++)
    {
        for(int j=1;j <= N;j++)
            cout <<matrix[i][j] <<" ";
        cout <<endl;
    }
    return 0;
}

void DAC(int n)
{
    if(n == 2)
    {
        matrix[1][1] = 1;
        matrix[1][2] = 2;
        matrix[2][1] = 3;
        matrix[2][2] = 1;
        return;
    }
    DAC(n/2);
    for(int i=1;i <= n/2;i++)
    {
        for(int j=1;j <= n/2;j++)
            matrix[i+n/2][j+n/2] = matrix[i][j];
    }
    for(int i=1;i <= n/2;i++)
    {
        for(int j=1;j <= n/2;j++)
            matrix[i][j+n/2] = matrix[i][j]+n;
    }
    for(int i=1;i <= n/2;i++)
    {
        for(int j=1;j <= n/2;j++)
        {
            if(i == j)
                matrix[i+n/2][j] = matrix[i][j+n/2]-1;
            else
                matrix[i+n/2][j] = matrix[i][j+n/2];
        }
    }
}
