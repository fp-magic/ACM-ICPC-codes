#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[2005][2005];
struct node
{
    int l,r;
    bool operator < (const node &w)const
    {
        return r<w.r||(r==w.r&&l<w.l);
    }
}a[2005];
int up[2005];
int main()
{
    int now,n,num,m,i,j,k,s,t,tt,step=0;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(up,0,sizeof(up));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            x[i]=a[i].l;
            x[i+m]=a[i].r;
            for(j=a[i].l;j<=a[i].r;j++)
                up[j]=max(up[j],a[i].r);
        }
        sort(x+1,x+2*m+1);
        sort(a+1,a+m+1);
        now=0;
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                f[i][j]=max(f[i][j],f[i][j-1]);
                f[i][j]=max(f[i][j],f[i-1][j]);
                if(up[i])
                {
                    f[up[i]][j]=max(f[up[i]][j],f[i-1][j-1]+up[i]-i+1);
                }
            }
        }
        printf("Case #%d: %d\n",++step,f[n][k]);
    }
    return 0;
}