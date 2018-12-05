#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[100005];
int main()
{
    int i,j,n,k;
    long long s,t;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    s=0;
    j=1;
    for(i=1;i<=k;i++)
    {
        while(j<=n&&a[j]<=s)j++;
        if(j>n)printf("0\n");
        else printf("%I64d\n",a[j]-s),s+=a[j]-s;
    }
    return 0;
}