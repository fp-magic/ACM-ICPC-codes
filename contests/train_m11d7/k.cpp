#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int>a[105][105];
int w[105];
int fff[105];
int dis[105][105];
int vit[105][105];
queue<int>qpre,q;
int main()
{
    int n,m,i,j,k,s,t,x;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&m,&w[i]);
            for(j=1;j<=m;j++)
            {
                scanf("%d%d",&s,&x);
                memset(fff,0,sizeof(fff));
                for(k=1;k<=s;k++)
                {
                    scanf("%d",&t);
                    if(i!=1)fff[t]=1;
                }
                for(k=1;k<=n;k++)
                    if(fff[k]==0)
                    {
                        a[k][i].push_back(x);
                    }
            }
        }
        while(!qpre.empty())qpre.pop();
        while(!q.empty())q.pop();
        for(i=2;i<=n;i++)
        {
            qpre.push(i);
            q.push(1);
        }
        memset(dis,127,sizeof(dis));
        for(i=2;i<=n;i++)dis[i][1]=w[1];
        memset(vit,0,sizeof(vit));
        for(i=2;i<=n;i++)vit[i][1]=1;
        while(!q.empty())
        {
            t=qpre.front();qpre.pop();
            s=q.front();q.pop();
            for(i=0;i<a[t][s].size();i++)
            {
                if(dis[s][a[t][s][i]]>dis[t][s]+w[a[t][s][i]])
                {
                    dis[s][a[t][s][i]]=dis[t][s]+w[a[t][s][i]];
                    if(!vit[s][a[t][s][i]])
                    {
                        vit[s][a[t][s][i]]=1;
                        qpre.push(s);
                        q.push(a[t][s][i]);
                    }
                }
            }
            vit[t][s]=0;
        }
        s=1e9;
        for(i=1;i<=n-1;i++)
            s=min(s,dis[i][n]);
        if(s==1e9)
            printf("impossible\n");
        else
            printf("%d\n",s);
    }
    return 0;
}