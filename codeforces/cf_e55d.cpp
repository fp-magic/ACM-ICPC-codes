#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int x,idx;
}a[505];
int cmp(node l,node r)
{
    return l.x<r.x;
}
int b[505][505],s;
vector<int>a0,a1,a2;
int add(int u,int v)
{
    if(b[a[u].idx][a[v].idx]!=1&&u!=v&&a[u].x&&a[v].x)
    {
        b[a[u].idx][a[v].idx]=1;
        b[a[v].idx][a[u].idx]=1;
        a[u].x--;//printf("%d %d\n",a[u].idx,a[v].idx);
        a[v].x--;
        s++;
        return 1;
    }
    return 0;
}
int main()
{
    int n,m,i,j,k,t,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].idx=i;
    }
    sort(a+1,a+n+1,cmp);

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(i==j)b[i][j]=0;
        else b[i][j]=1000000000;
    }
    s=0;
    if(n==2)
    {
        add(1,2);
    }else
    if(n==3)
    {
        if(a[3].x>=2)
            add(1,3),add(2,3);
    }else
    {
        for(i=n-1;i>=1;i--)
        {
            j=i+1;
            while(!add(i,j)&&j<=n)j++;
        }
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=n;k++)
    if(i!=j&&i!=k&&j!=k)
    b[j][k]=min(b[j][k],b[j][i]+b[i][k]);
    t=0;
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    {//printf("=%d %d %d\n",i,j,b[i][j]);
        t=max(t,b[i][j]);
    }
    if(t>=1000000000)
        printf("NO\n");
    else
    {
        printf("YES %d\n",t);
        printf("%d\n",s);
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        if(b[i][j]==1)
        printf("%d %d\n",i,j);
    }
    return 0;
}