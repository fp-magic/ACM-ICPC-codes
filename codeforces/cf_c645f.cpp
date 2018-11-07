#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
/*
利用欧拉函数的性质的一道题，表面挺麻烦，推出公式就好做了
*/
const ll mod=1e9+7;
map<ll,ll>f;
map<ll,ll>::iterator it;
ll m=1100000,phi[1100005],prime[1100005],tot;
bool np[1100005];
ll a[100005],fac[1100005],inv[1100005],sum[1100005];
ll power(ll x,ll y){
    ll tmp=1;
    for(;y;y>>=1,x=x*x%mod)
    if(y&1) tmp=tmp*x%mod;
    return tmp;
}
void Get_phi()
{
    ll i,j;
    phi[1] = sum[1] = 1;
    for(i = 2 ; i <= m ; i ++ )
    {
        if(!np[i]) phi[i] = i - 1 , prime[++tot] = i;
        for(j = 1 ; j <= tot && i * prime[j] <= m ; j ++ )
        {
            np[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    fac[0]=1;
    for(i=1;i<=m;i++)fac[i]=(fac[i-1]*i)%mod;
    inv[m]=power(fac[m],mod-2);
    for(i=m-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m){
    if(n<m) return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
    ll n,i,j,k,s,t,q,ans=0;
    Get_phi();
    scanf("%I64d%I64d%I64d",&n,&k,&q);
    for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
    memset(sum,0,sizeof(sum));
    for(i=1;i<=n;i++)
    {
        for(j=1;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                sum[j]++;
                if(a[i]!=j*j)
                    sum[a[i]/j]++;
            }
    }
    for(i=1;i<=m;i++)
    {
        ans=(ans+phi[i]*C(sum[i],k))%mod;
    }
    for(i=1;i<=q;i++)
    {
        scanf("%I64d",&s);
        for(j=1;j*j<=s;j++)
            if(s%j==0)
            {
                ans=(ans+phi[j]*(C(sum[j]+1,k)-C(sum[j],k)))%mod;
                sum[j]++;
                if(s!=j*j)
                {
                    t=s/j;
                    ans=(ans+phi[t]*(C(sum[t]+1,k)-C(sum[t],k)))%mod;
                    sum[t]++;
                }
            }
        printf("%I64d\n",(ans+mod)%mod);
    }
    
    return 0;
}