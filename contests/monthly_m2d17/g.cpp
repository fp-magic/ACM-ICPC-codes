#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll a[400005];
ll b[400005];
ll c[400005];
ll d[400005];
ll e[400005];
ll f[400005];
int main()
{
    ll n,m,q,i,j,k,s,t,tt,rest;
    scanf("%lld",&tt);
    while(tt--)
    {
        scanf("%lld%lld%lld",&n,&m,&q);
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(i=0;i<m;i++)scanf("%lld",&d[i]);
        sort(d,d+m);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i=0;i<m;i++)
            for(j=(d[i]==n?1:(d[i]+1));j!=(d[(i+1)%m]==n?1:(d[(i+1)%m]+1));j=(j==n?1:(j+1)))
                c[j]=i,b[i]=max(b[i],a[j]);
        if(m==0||m==1)for(i=1;i<=n;i++)b[0]=max(b[0],a[i]);
        rest=max(m,1ll);
        memset(f,0,sizeof(f));
        //for(i=1;i<=n;i++)printf("%lld ",c[i]);printf("\n");
        for(i=1;i<=q;i++)scanf("%lld%lld",&d[i],&e[i]);
        //for(j=1;j<=n;j++)printf("%d ",b[c[j]]);printf("\n");
        for(i=1;i<=q;i++)
        {
            b[c[d[i]]]-=e[i];
            if(b[c[d[i]]]<=0&&!f[c[d[i]]])rest--,f[c[d[i]]]=1;
            if(rest<=0)
            {
                printf("%lld\n",i);
                break;
            }
            //for(j=1;j<=n;j++)printf("%d ",b[c[j]]);printf("\n");
        }
        if(rest>0)printf("False Promise!\n");
    }
    return 0;
}