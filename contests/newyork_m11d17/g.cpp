#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int f[35];
int main()
{
    int n,m,i,j,k,s,t,tt,kk;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d %d %d %d",&s,&n,&m,&kk);
        memset(f,0,sizeof(f));
        f[0]=1;
        for(j=1;j<=n;j++)
            for(i=1;i<=j;i++)
            if((i-m)%kk!=0)
                f[j]+=f[j-i];
        printf("%d %d\n",s,f[n]);
    }
    return 0;
}