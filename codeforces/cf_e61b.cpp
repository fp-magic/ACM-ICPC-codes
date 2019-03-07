#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
ll a[300005];
ll sum; 
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    scanf("%d",&m);
    sum=0;
    for(i=1;i<=n;i++)sum+=a[i];
    for(i=1;i<=m;i++)
    {
        scanf("%d",&t);
        printf("%I64d\n",sum-a[n-t+1]);
    }
    return 0;
}