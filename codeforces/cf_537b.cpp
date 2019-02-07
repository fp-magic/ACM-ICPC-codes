#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
long long a[100005];
int main()
{
    long long n,m,i,j,k;
    double ans=0;
    long long s,num;
    scanf("%I64d%I64d%I64d",&n,&k,&m);
    for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    s=0;
    for(i=1;i<=n;i++)s+=(ll)a[i];
    for(i=1;i<=n&&m>=0;i++)
    {
        ans=max(ans,((double)min(s+m,s+(n-i+1)*k))/((double)(n-i+1)));
        //printf("%I64d %d \n",min(s+m,s+(n-i+1)*k));
        s-=a[i];
        m--;
    }
    printf("%.8f\n",ans);
    return 0;
}