#include<cstdio>
#include<map>
#define ll long long
using namespace std;
/*
杜教筛无预处理版模板题，时间复杂度为O(n3/4logn)
*/
map<ll,ll>f;
map<ll,ll>::iterator it;
ll query(ll n)
{
    it=f.find(n);
    if(it!=f.end())return it->second;
    ll ans=n*(n+1)/2,i,last;
    for(i=2;i<=n;i=last+1)last=n/(n/i),ans-=(last-i+1)*query(n/i);
    f.insert(make_pair(n,ans));
    return ans;
}
int main()
{
    ll n,m,i,j,k,s,t;
    scanf("%lld",&n);
    printf("%lld\n",query(n));
    return 0;
}