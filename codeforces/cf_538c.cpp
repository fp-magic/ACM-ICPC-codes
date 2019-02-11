#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
        b =(b*b)%mod;exp/=2ll;
    }
    return res;
}
ll f[10005],g[10005],tot;
int main()
{
    ll n,m,i,j,k,s,t,a,b,num,ans;
    scanf("%I64d%I64d",&a,&b);
    t=b;
    tot=0;
    s=0;num=1;
    for(i=2;i<=sqrt(b)+1;i++)
    {
        if(t%i==0)
        {
            num=0;
            while(t%i==0)t/=i,num++;
            f[++tot]=i;
            g[tot]=num;
        }
    }
    if(t!=1)f[++tot]=t,g[tot]=1;
    ans=(long long)1e18;//printf("%I64d\n",ans);
    for(j=1;j<=tot;j++)
    {
        t=0;k=f[j];
        for(i=1;i<=100;i++)
        {
            t+=(a/k);//printf("%I64d %I64d\n",k,a/k);
            if(k>a/f[j]+1)break;
            k=k*f[j];
        }
        ans=min(ans,t/g[j]);
    }
    printf("%I64d\n",ans);
    return 0;
}