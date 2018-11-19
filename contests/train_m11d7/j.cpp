#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105],p[105];
int f[105][105];
int main()
{
    int n,m,c,i,j,k,s,t;
    while(scanf("%d%d",&c,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&s);
                for(k=c;k>=j;k--)
                {
                    f[i][k]=max(f[i][k],max(f[i-1][k],f[i-1][k-j]+s));
                }
            }
        }
        printf("%d\n",f[m][c]);
    }
    return 0;
}