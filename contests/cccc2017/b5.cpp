#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;
double a[105][105];
double dis[105][105][2];
int vis[105][105][2];
int n,m;
int d[4][2],e[4][2];
queue<int>qx,qy,qz;
int lx,ly,rx,ry,x,y,z,sx,sy,sz;
int dx,dy;
int dot(int px,int py,int qx,int qy){return px*qy-qx*py;}
double spfa(int flag)
{
    int i,j;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)dis[i][j][0]=1e9,dis[i][j][1]=1e9;
    dis[lx][ly][0]=a[lx][ly];
    while(!qx.empty())qx.pop();
    while(!qy.empty())qy.pop();
    while(!qz.empty())qz.pop();
    qx.push(lx);
    qy.push(ly);
    qz.push(0);
    memset(vis,0,sizeof(vis));
    vis[lx][ly][0]=1;   
    while(!qx.empty()){
        x=qx.front();qx.pop();
        y=qy.front();qy.pop();
        z=qz.front();qz.pop();
        vis[x][y][z]=0;
        //printf("%d %d %d\n",x,y,z);
        for(i=0;i<4;i++)
        {
            sx=x+d[i][0];sy=y+d[i][1];
            if(dot(sx-lx,sy-ly,rx-lx,ry-ly)*flag>0||(sx==rx&&sy==ry))
            if(sx>=1&&sx<=n&&sy>=1&&sy<=m&&dis[sx][sy][0]>dis[x][y][z]+a[sx][sy])
            {
                dis[sx][sy][0]=dis[x][y][z]+a[sx][sy];
                if(!vis[sx][sy][0])
                {
                    qx.push(sx);qy.push(sy);qz.push(0);
                    vis[sx][sy][0]=1;
                }
            }
        }
        for(i=0;i<4;i++)
        {
            sx=x+e[i][0];sy=y+e[i][1];
            double cnt;
            cnt=(sqrt(2.0)-1.0)*a[x][y]+sqrt(2.0)*a[sx][sy];
            //else cnt=sqrt(2.0)*a[sx][sy];
            if(dot(sx-lx,sy-ly,rx-lx,ry-ly)*flag>0||(sx==rx&&sy==ry))
            if(sx>=1&&sx<=n&&sy>=1&&sy<=m&&dis[sx][sy][1]>dis[x][y][z]+cnt)
            {
                dis[sx][sy][1]=dis[x][y][z]+cnt;
                if(!vis[sx][sy][1])
                {
                    qx.push(sx);qy.push(sy);qz.push(1);
                    vis[sx][sy][1]=1;
                }
            }
        }
    }
    return min(dis[rx][ry][0],dis[rx][ry][1]);
}
int main()
{
    d[0][0]=1;d[0][1]=0;d[1][0]=-1;d[1][1]=0;
    d[2][0]=0;d[2][1]=1;d[3][0]=0;d[3][1]=-1;
    e[0][0]=1;e[0][1]=1;e[1][0]=1;e[1][1]=-1;
    e[2][0]=-1;e[2][1]=1;e[3][0]=-1;e[3][1]=-1;
    int i,j,k,s,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%lf",&a[i][j]);
    scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
    lx++;ly++;rx++;ry++;
    swap(lx,ly);swap(rx,ry);
    
    printf("%.2f\n",spfa(-1)+spfa(1)-a[lx][ly]);
    return 0;
}