#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
/*
保存每个点的dfs序内出现位置编号low和high
对于每个询问，，找最小的两个low和最大的两个high,设为lowest,low,highest,high
然后分别求lca(lowest,highest)lca(low,highest)lca(lowest,high)
然后判断几种情况就可以了（应该是三种）
由于到睡觉时间了，代码未完成。咕。
*/
int low[100005], high[1000005];
int n, step;
vector<int> a[100005];
struct node
{
    int x, v;
    friend bool operator<(node &l, node &r)
    {
        return l.x<r.x;
    }
    friend bool operator>(node &l, node &r)
    {
        return l.x>r.x;
    }
}ma[500005], mi[500005];
int ll, rr;
struct query
{
    int u,v,lca,idx;
};
vector<query>qu[100005];
int p[100005];
int lq[100005],rq[100005];
int ans[100005];
int vis[100005];
int depth[100005];
void build(int pl, int pr, int x)
{
    if (pl == pr)
    {
        step++;
        mi[step].x=low[step];mi[step].v=step;
        ma[step].x=high[step];ma[step].v=step;
    }
    else
    {
        int mid = (pl + pr) / 2;
        build(pl, mid, 2 * x);
        build(mid + 1, pr, 2 * x + 1);
        mi[x]=min(mi[x*2],mi[x*2+1]);
        ma[x]=max(ma[x*2],ma[x*2+1]);
    }
}
node findmin(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)return(mi[x]);
    else
    {
        int m=(pl+pr)/2;
        node ans;
        ans.x=9999999;
        if(ll<=m)ans=min(ans,findmin(pl,m,2*x));
        if(rr>=m+1)ans=min(ans,findmin(m+1,pr,2*x+1));
        return ans;
    }
}
node findmax(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)return(ma[x]);
    else
    {
        int m=(pl+pr)/2;
        node ans;
        ans.x=0;
        if(ll<=m)ans=max(ans,findmax(pl,m,2*x));
        if(rr>=m+1)ans=max(ans,findmax(m+1,pr,2*x+1));
        return ans;
    }
}
void dfs(int x, int step)
{
    low[x] = ++step;
    for (int i = 0; i < a[x].size(); i++)
        if (low[a[x][i]] == -1)
            dfs(a[x][i]);
    high[x] = ++step;
}
int fin(int x)
{
    if(p[x]!=x)p[x]=fin(p[x]);return p[x];
}
void unio(int x,int y)
{
    int px=fin(x),py=fin(y);
    if(px!=py)p[px]=py;
}
void lca(int u,int father,int d)
{
    vis[u]=1;
    p[u]=u;
    depth[u]=d;
    for(int i=0;i<a[u],size();i++)
    if(!vis[a[u][i])
    {
        lca(a[u][i],u,d+1);
        p[v]=u;
    }
    for(int i=0;i<qu[u].size();i++)
    if(!vis[qu[u][i].v])
    {
        ans[qu[u][i].idx]=find(v);
    }
}
int main(
{
    int q, i, j, k, s, t;
    node tmp;
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++)
        a[i].clear();
    for (i = 2; i <= n; i++)
    {
        scanf("%d", &k);
        a[k].push_back(i);
    }
    memset(low, 255, sizeof(low));
    memset(high, 255, sizeof(high));
    step = 0;
    dfs(1);
    step=0;
    build(1,n,1);
    for(i=1;i<=n;i++)qu[i].clear();
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&s,&t);
        lq[i]=s;rq[i]=t;
        ll=s;rr=t;tmp.u=findmin(1,n,1).v;
        ll=s;rr=t;tmp.v=findmax(1,n,1).v;
        tmp.idx=i;
        qu[tmp.u].push_back(tmp);
        step(tmp.u,tmp.v);
        qu[tmp.u].push_back(tmp);
    }
    for(i=1;i<=n;i++)p[i]=i;
    memset(vis,0,sizeof(vis));
    lca(1,0,0);
    return 0;
}