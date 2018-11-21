#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
    bool operator < (const node & r)const
    {
        return x-y>r.x-r.y;
    }
};
int cmp(node l,node r)
{
    return l.x+l.y<r.x+r.y;
}
struct node2
{
    int x,idx;
};
int cmp2(node2 l,node2 r)
{
    return l.x<r.x;
}
node a[200005];
node2 x[200005];
int ans[200005];
priority_queue<node>q;
int main()
{
    int n,m,l,k,i,j,s,t;
    scanf("%d%d%d",&n,&m,&l);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=m;i++)
        scanf("%d",&x[i].x),x[i].idx=i;
    sort(x+1,x+m+1,cmp2);
    while(!q.empty())q.pop();
    j=1;
    for(i=1;i<=m;i++)
    {//printf("%d\n",i);
        while(j<=n&&a[j].x+a[j].y<=x[i].x+l)
        {
            q.push(a[j]);//printf("push%d %d\n",a[j].x,a[j].y);
            j++;
        }
        while(!q.empty()&&q.top().x-q.top().y<x[i].x-l)
        {//printf("pop%d %d\n",q.top().x,q.top().y);
            q.pop();
        }
        ans[x[i].idx]=q.size();
    }
    for(i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}