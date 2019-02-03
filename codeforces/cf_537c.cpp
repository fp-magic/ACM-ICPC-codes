#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100005],k,sa,sb;
ll dfs(ll l,ll r)
{
    ll n1,n2,n3,s1,s2;
    n1=lower_bound(a+1,a+k+1,l)-a;
    n2=upper_bound(a+1,a+k+1,r)-a;
    if(l==r)
    {
        if(n1==n2)return sa;
        else return sb*(n2-n1);
    }
    if(n2==n1)s1=sa;else s1=sb*(r-l+1)*(n2-n1);
    s2=0;
    n3=upper_bound(a+1,a+k+1,(l+r)/2)-a;
    if(n3==n1)s2+=sa;else s2+=dfs(l,(l+r)/2);
    if(n3==n2)s2+=sa;else s2+=dfs((l+r)/2+1,r);
    return min(s1,s2);
}
int main()
{
    ll n,m,i,j,s,t;
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&sa,&sb);
    for(i=1;i<=k;i++)scanf("%I64d",&a[i]);
    sort(a+1,a+k+1);
    printf("%I64d\n",dfs(1,1<<n));
    return 0;
}