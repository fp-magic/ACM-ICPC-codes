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
int a[200005],f[200005];
pair<int,int>b[200005];
int main()
{
    int n,m,i,j,k,s,t;
    ll ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=make_pair(a[i],i);
    sort(b+1,b+n+1);
    memset(f,0,sizeof(f));
    for(i=n;i>=n-m*k+1;i--)f[b[i].second]=1,ans+=(long long)b[i].first;
    printf("%I64d\n",ans);
    s=0;t=0;
    for(i=1;i<=n;i++)
    {
        if(f[i])s++;
        if(s>=m)
        {
            printf("%d ",i);
            s=0;
            t++;
            if(t>=k-1)break;
        }
    }
    return 0;
}