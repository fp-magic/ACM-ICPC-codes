#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
long long a[100005][2];
int main()
{
    int n,m,i,j,k,t;
    long long s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d%I64d",&a[i][0],&a[i][1]);
    s=0;
    for(i=2;i<n;i++)
        s=s+(a[i][0]-a[1][0])*(a[i+1][1]-a[1][1])-(a[i][1]-a[1][1])*(a[i+1][0]-a[1][0]);
    s=abs(s);
    //printf("%I64d\n",s);
    for(i=1;i<n;i++)
        s-=__gcd(abs(a[i+1][1]-a[i][1]),abs(a[i+1][0]-a[i][0]))-1;
    s-=__gcd(abs(a[1][1]-a[n][1]),abs(a[1][0]-a[n][0]))-1;
    printf("%I64d\n",(s-n+2)/2);
    return 0;
}