#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 100000007700000049;
ll f[100005],pre[100005];
int main()
{
    ll n,m,i,j,k,s,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=1;i<=m;++i)f[i]=2;
        pre[0]=1;
        for(i=1;i<=m;++i)pre[i]=pre[i-1]+f[i];
        for(i=2;i<=n;++i)
        {
            for(j=m;j>=1ll;--j)
                f[j]=(pre[j-1]*2ll+f[j])%mod;
            //for(j=0ll;j<=m;j++)printf("%lld ",f[j]);printf("\n");
            for(j=1ll;j<=m;++j)
                pre[j]=(f[j]+pre[j-1])%mod;    
            //for(j=0ll;j<=m;j++)printf("%lld ",pre[j]);printf("\n");    
        }
        printf("%lld\n",pre[m]);
    }
    return 0;
}