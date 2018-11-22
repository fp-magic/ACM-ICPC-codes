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
        scanf("%d%d%d",&n,&m,&k);
        s=0;t=0;
        if(n>m)
        {
            printf("Case #%d: %d\n",++step,k);
            continue;
        }
        for(i=1;i<=k;i++)
        {
           if(s<m*11-n*9)
           {
               s+=n*11;
           }else
           {
                s-=m*11-n*9;
                t++;
           }
        }
        printf("Case #%d: %d\n",++step,t);
    }
    return 0;
}