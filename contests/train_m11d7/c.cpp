#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[1000000];
int main()
{
    long long a[25];
    long long n,m,i,j,k,s,t;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        s=a[1];
        for(i=2;i<=n;i++)
            s=__gcd(s,a[i]);
        if(k%s!=0)
        {
            printf("impossible\n");
            continue;
        }
        for(i=1;i<=n;i++)a[i]/=s;
        k/=s;
        if(k>=1000000)
        {
            printf("possible\n");
            continue;
        }
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=1;i<=1000000;i++)
        {
            for(j=1;j<=n;j++)
            if(a[j]<=i)
                f[i]=f[i]|f[i-a[j]];
        }
        if(f[k])
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}
