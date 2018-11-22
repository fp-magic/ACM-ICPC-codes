#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int tt,n,m,i,j,k,s,t,step=0;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        s=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            s+=t+(t+9)/10;
        }
        printf("Case #%d: %d\n",++step,s);
    }
    return 0;
}