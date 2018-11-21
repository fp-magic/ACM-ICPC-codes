#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a[105];
vector<int>x;
int vit[105],p[105],dis[105][105];
int n,m,ans;
void dfs(int fa,int x,int d)
{
    vit[x]=1;
    dis[fa][x]=d;
    for(int i=0;i<a[x].size();i++)
    if(!vit[a[x][i]])
    {
        dfs(fa,a[x][i],d+1);
    }
}
int main()
{
    int i,j,k,s,t,ff,nm;
    scanf("%d%d",&n,&m);
    memset(p,0,sizeof(p));
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]),a[i].clear();
    for(i=1;i<=n-1;i++)
    {
        scanf("%d%d",&s,&t);
        a[s].push_back(t);
        a[t].push_back(s);
    }
    ans=n;
    for(i=1;i<=n;i++)
    {
        memset(vit,0,sizeof(vit));
        dfs(i,i,0);
    }
    for(i=1;i<=n;i++)
    if(p[i])
        for(j=i+1;j<=n;j++)
        if(p[j])
        {
            s=dis[i][j];
            if(s>ans)continue;
            x.clear();nm=0;
            for(k=1;k<=n;k++)
            if(p[k])
                if(dis[i][k]<=s&&dis[k][j]<=s)
                    x.push_back(k),nm++;
            if(nm<m)continue;
            ans=s;
        }
    if(m==1)ans=0;
    printf("%d\n",ans);
    return 0;
}