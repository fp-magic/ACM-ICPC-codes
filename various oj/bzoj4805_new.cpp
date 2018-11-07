#include<cstdio>
#include<map>
#define ll long long
using namespace std;
/*
杜教筛带预处理版模板题，需要预处理出n^2/3以内的phi值，总时间复杂度为O(n2/3logn)
时间12480ms->1156ms
*/
map<ll,ll>f;
map<ll,ll>::iterator it;
ll m=1600000,phi[1600005],prime[1600005],sum[1600005],tot;
bool np[1600005];
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
        sum[i] = sum[i - 1] + phi[i];
    }
}
ll query(ll n)
{
    if(n<=m)return sum[n];
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
    Get_phi();
    scanf("%lld",&n);
    printf("%lld\n",query(n));
    return 0;
}