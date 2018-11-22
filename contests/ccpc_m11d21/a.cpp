#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int tt,n,m,i,j,k,s,t,step=0;
    double ans;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        ans=n-1;
        printf("Case #%d: %.10lf\n",++step,ans);
    }
    return 0;
}