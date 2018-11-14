#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,i,j,k,s,t;
    scanf("%I64d",&n);
    s=0;
    for(i=2;i<=n;i++)
    if(n/i>1)
    {
        s=s+(2+n/i)*(n/i-1)/2*4;
    }
    printf("%I64d\n",s);
    return 0;
}