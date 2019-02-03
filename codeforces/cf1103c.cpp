#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int>a[250005],now;
int d[250005],p[250005],isleaf[250005];
int n,m,k;
void dfs(int x,int depth)
{
    d[x]=depth;
    for(int i=0;i<a[x].size();i++){
        if(d[a[x][i]]==-1)
        {
            p[a[x][i]]=x;
            isleaf[x]=0;
            dfs(a[x][i],depth+1);
        }
    }
}
void output(int x,int stop)
{
    now.clear();
    while(x!=stop)
    {//printf("%d %d\n",x,stop);
        now.push_back(x);
        x=p[x];
    }
    for(int i=0;i<now.size();i++)
        printf("%d ",now[i]);
}
int main()
{
    int i,j,u,v,s,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)a[i].clear();
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(p,255,sizeof(p));
    memset(d,255,sizeof(d));
    for(i=1;i<=n;i++)isleaf[i]=1;
    dfs(1,0);
    //for(i=1;i<=n;i++)printf("%d ",p[i]);printf("\n");
    for(i=1;i<=n;i++)
    if(d[i]+1>=(n-1)/k+1)
    {
        printf("PATH\n");
        printf("%d\n",d[i]+1);
        output(i,-1);
        printf("\n");
        return 0;
    }
    printf("CYCLES\n");
    s=0;
    for(i=1;i<=n&&s<k;i++)
    if(isleaf[i])
    {
        s++;
        u=-1;v=-1;
        for(j=0;j<a[i].size();j++)
        if(a[i][j]!=p[i])
        {
            if(u==-1)
                u=a[i][j];
            else
            if(v==-1)
                v=a[i][j];
            else
                break;
        }
        //printf("%d %d=%d %d\n",u,v,i,p[i]);
        if(d[u]<d[v])swap(u,v);
        if((d[i]-d[u]+1)%3!=0)
        {
            printf("%d\n",d[i]-d[u]+1);
            output(i,p[u]);
            printf("\n");
        }else
        if((d[i]-d[v]+1)%3!=0)
        {
            printf("%d\n",d[i]-d[v]+1);
            output(i,p[v]);
            printf("\n");
        }else
        if((d[u]-d[v]+2)%3!=0)
        {
            printf("%d\n",d[u]-d[v]+2);
            output(u,p[v]);
            printf("%d\n",i);
        }else
            printf("-1\n");
    }
    return 0;
}