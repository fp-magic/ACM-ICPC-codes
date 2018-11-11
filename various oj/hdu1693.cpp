#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
插头dp模板题
*/
int a[13][13];
long long f[13][13][4100];
int n,m;
void solve(int x,int y)
{
    int l=1<<(y-1),r=1<<(y),i,j,tmp=1<<(m+1);
    long long s,t;
    if(y==0)
    {
        for(i=0;i*2<tmp;i++)
            f[x][0][i*2]=f[x-1][m][i];
        return;       
    }
    if(!a[x][y])
    {
        for(i=0;i<tmp;i++)
            if((!(i&l))&&(!(i&r)))
                f[x][y][i]+=f[x][y-1][i];
        return;
    }
    for(i=0;i<tmp;i++)
    {
        f[x][y][i]+=f[x][y-1][i^l^r];
        if(((i&l)&&(i&r))||((!(i&l))&&(!(i&r))))continue;
        f[x][y][i]+=f[x][y-1][i];
    }
}
int main()
{
    int tt,i,j,k,step=0;
    scanf("%lld",&tt);
    while(tt--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(f,0,sizeof(f));
        f[0][m][0]=1;
        for(i=1;i<=n;i++)
            for(j=0;j<=m;j++)
                solve(i,j);
        printf("Case %d: There are %lld ways to eat the trees.\n",++step,f[n][m][0]);
    }
    return 0;
}