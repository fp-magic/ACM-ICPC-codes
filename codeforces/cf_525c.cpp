#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[2005];
int main()
{
    int n,i,j,k;
    long long s,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    s=0;
    printf("%d\n",n+1);
    for(i=n;i>=1;i--)
    {
        t=n+i-1-((a[i]+s)%n);
        printf("1 %d %I64d\n",i,t);
        s=(s+t)%n;
    }
    printf("2 %d %d\n",n,n);
    return 0;
}