#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n,m,i,j,k,s,t,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    s=0;t=0;
    l=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]+1)
        {
            s=max(s,i-l-1);
            if(a[l]==1)s=max(s,i-l);
        }else
            l=i;
    }
    if(l!=n)
    {
        s=max(s,n-l-1);
        if(a[n]==1000)s=max(s,n-l);
    }

    printf("%d\n",s);
    return 0;
}