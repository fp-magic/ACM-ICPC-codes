#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define mkp make_pair
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
vector<pair<int,ll> >a[100005];
ll a[100005]
ll dfs(int x,int left)
{

}
int main()
{
    int n,m,i,j,k,u,v,s,t;
    ll w;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            a[u].pb(mkp(v,w));
            a[v].pb(mkp(u,w));
        }
        memset(f,0,sizeof(f));
        printf("%lld\n",dfs((1+n)/2,k));
    }
    return 0;
}