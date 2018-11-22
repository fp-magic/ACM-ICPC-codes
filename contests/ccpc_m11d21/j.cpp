#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>a[2005];
vector<long long>b[2005];
int flag[2005];
long long dis[2005];
int vitnum[2005];
queue<int>q;
int n;
bool spfa()
{
    q.push(1);flag[1]=1;dis[1]=0;
    int i,s,t;
    while(!q.empty())
    {
        s=q.front();q.pop();vitnum[s]++;
        if(vitnum[s]>n)return false;
        for(i=0;i<a[s].size();i++)
        {
            if(dis[a[s][i]]>dis[s]+b[s][i])
            {
                dis[a[s][i]]=dis[s]+b[s][i];
                if(!flag[a[s][i]])
                {
                    flag[a[s][i]]=1;
                    q.push(a[s][i]);
                }
            }
        }
        flag[s]=0;
    }
    return true;
}
int main()
{
    int m,i,j,k,s,t,tt,u1,v1,x,u2,v2,step=0;
    long long tmp=1e9+1e9;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d",&n,&m,&x);
        for(i=1;i<=n;i++)a[i].clear(),b[i].clear();
        for(i=1;i<n;i++)a[i+1].push_back(i),b[i+1].push_back(-1),a[i].push_back(i+1),b[i].push_back(tmp);
        memset(dis,127,sizeof(dis));
        memset(flag,0,sizeof(flag));
        memset(vitnum,0,sizeof(vitnum));
        while(!q.empty())q.pop();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&u1,&v1,&u2,&v2);
            if(u1==v1&&u2==v2)
            {
                a[v2].push_back(u1);
                b[v2].push_back(-x);
                a[u1].push_back(v2);
                b[u1].push_back(x);
            }else
            if(u1==u2||v1==v2)
            {
                a[v2].push_back(u1);
                b[v2].push_back(-x-1);//printf("%d -> %d: %d\n",v2,u1,-x-1);
            }else
            {
                a[v1].push_back(u2);
                b[v1].push_back(x-1);//printf("%d -> %d: %d\n",v1,u2,x-1);
                a[v2].push_back(u1);
                b[v2].push_back(-x-1);//printf("%d -> %d: %d\n",v2,u1,-x-1);
            }
        }
        if(!spfa())
            printf("Case #%d: IMPOSSIBLE\n",++step);
        else
        {
            printf("Case #%d:",++step);
            for(i=2;i<=n;i++)printf(" %lld",dis[i]-dis[i-1]);
            printf("\n");
        }
    }
    return 0;
}