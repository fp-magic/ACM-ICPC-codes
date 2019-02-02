#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
int a[405][405],n;
int flag[405],dis[405];
int main()
{
    int m,i,j,k,s,t;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(flag));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&s,&t);
        a[s][t]=1;a[t][s]=1;
    }
    if(a[1][n]==1)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=1-a[i][j];
    }
    for(i=1;i<=n;i++)dis[i]=100000;
    dis[1]=0;
    queue<int>q;while(!q.empty())q.pop();
    q.push(1);
    flag[1]=1;
    while(!q.empty())
    {
        s=q.front();q.pop();
        for(i=1;i<=n;i++)
        if(a[s][i]==1)
        {
            if(dis[i]>dis[s]+1)
            {
                dis[i]=dis[s]+1;
                if(!flag[i])
                {
                    q.push(i);
                    flag[i]=1;
                }
            }
        }
        flag[s]=0;
    }
    if(dis[n]==100000)dis[n]=-1;
    printf("%d\n",dis[n]);
    return 0;
}