#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n,m,i,j;
    double a,b,c,d,k,p,s,t,ans;
    scanf("%lf%lf%lf%lf%lf",&p,&a,&b,&c,&d);
    scanf("%d",&n);
    ans=0;
    s=p*(sin(a+b)+cos(c+d)+2);
    for(i=2;i<=n;i++)
    {
        t=p*(sin(a*i+b)+cos(c*i+d)+2);
        ans=max(ans,s-t);
        s=max(s,t);
    }
    printf("%.8f",ans);
    return 0;
}