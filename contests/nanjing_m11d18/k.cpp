#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int n,m,a[25][25];
int route[25][25][25][25];//0 up,1 lest,2 right,3 down
int vit[25][25];
int d[4][2];
vector<int>x,y;
void dfs(int nx,int ny,int dir)
{printf("%d %d %d\n",nx,ny,dir);
    int i,k,mx,my;
    vit[nx][ny]=1;
    x.push_back(nx);y.push_back(ny);
    for(i=0;i<x.size();i++)
    {
        mx=x[i];my=y[i];
        route[nx][ny][mx][my]=3-dir;
    }
    for(k=0;k<4;k++)
    {
        mx=nx+d[k][0];my=ny+d[k][1];
        if(!vit[mx][my]&&a[mx][my])
            dfs(mx,my,k);   
    }
    x.pop_back();y.pop_back();
}
int main()
{
    int i,j,k,s,t;
    d[0][0]=0;d[0][1]=1;d[1][0]=-1;d[1][1]=0;
    d[2][0]=1;d[2][1]=0;d[3][0]=0;d[3][1]=-1;
    memset(a,0,sizeof(a));
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%1d",&a[i][j]);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            if(a[i][j])
            {printf("%d %d\n",i,j);
                memset(vit,0,sizeof(vit));
                x.clear();y.clear();
                vit[i][j]=1;
                x.push_back(i);y.push_back(j);
                for(k=0;k<4;k++)
                if(a[i+d[k][0]][j+d[k][1]])
                    dfs(i+d[k][0],j+d[k][1],k);
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                for(s=1;s<=n;s++)
                    for(t=1;t<=n;t++)
                    if(a[i][j]&&a[s][t]);
                        printf("%d %d %d %d: %d\n",i,j,s,t,route[i][j][s][t]);
    }
    return 0;
}