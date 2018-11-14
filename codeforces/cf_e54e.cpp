#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    long long num;
    int bd,ed;
    friend bool operator < (node l,node r)
    {
        return l.ed>r.ed;
    }
};
vector<int>a[300005],d[300005];
vector<long long>x[300005];
long long ans[300005];
int flag[300005];
priority_queue<node>p;
void dfs(int now,long long sum,int depth)
{//printf("%d %I64d %d\n",now,sum,depth);
    flag[now]=1;
    node tmp;
    queue<node>q;
    while(!q.empty())q.pop();
    for(int i=0;i<x[now].size();i++)
    {
        sum+=x[now][i];
        tmp.bd=now;
        tmp.num=-x[now][i];
        tmp.ed=depth+d[now][i];
        p.push(tmp);
    }
    ans[now]=sum;
    while(!p.empty())
    {
        tmp=p.top();
        if(tmp.ed<=depth||flag[tmp.bd]==2)
        {
            sum+=tmp.num;
            p.pop();
            if(flag[tmp.bd]!=2)q.push(tmp);
        }else break;
    }
    for(int i=0;i<a[now].size();i++)
    if(!flag[a[now][i]])
    {
        dfs(a[now][i],sum,depth+1);
    }
    while(!q.empty())
    {
        tmp=q.front();q.pop();
        p.push(tmp);
    }
    flag[now]=2;
}
int main()
{
    int n,m,i,j,k,u,v;
    long long t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)a[i].clear(),x[i].clear(),d[i].clear();
    for(i=1;i<=n-1;i++)
    {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&v,&k,&t);
        x[v].push_back(t);
        d[v].push_back(k);
    }
    memset(flag,0,sizeof(flag));
    dfs(1,0,0);
    while(!p.empty())p.pop();
    for(i=1;i<=n;i++)
        printf("%I64d ",ans[i]);
    printf("\n");
    return 0;
}