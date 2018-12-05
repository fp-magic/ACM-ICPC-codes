#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,x,y,d,i,j,k,s,t,tt;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    for(j=1;j<=x;j++)
    if(i%j==0&&i*j>x&&i/j<x)
    {
        printf("%d %d\n",i,j);
        return 0;
    }
    printf("-1\n");
    return 0;
}