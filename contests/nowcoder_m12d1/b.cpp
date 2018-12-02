#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct node
{
    int l,r;
};
int cmp(node x,node y)
{
    return x.l<y.l;
}
int a[1000005];
node ll[1000005],rr[1000005];
stack<int>q;
int main()
{
    int tt,n,m,i,j,k,s,t,nl,nr,pl,pr,flag;
    node tmp;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            a[k]=i;
        }
        nl=0;nr=0;
        for(i=1;i<n;i+=2)//ll是左侧区间，rr是右侧区间
        {
            ll[++nl].l=min(a[i],a[i+1]);
            ll[nl].r=max(a[i],a[i+1]);
        }
        for(i=2;i<n;i+=2)
        {
            rr[++nr].l=min(a[i],a[i+1]);
            rr[nr].r=max(a[i],a[i+1]);
        }
        sort(ll+1,ll+nl+1,cmp);//按区间左边界排序
        sort(rr+1,rr+nr+1,cmp);
        /*for(i=1;i<=nl;i++)
        printf("%d %d\n",ll[i].l,ll[i].r);
        printf("\n");
        for(i=1;i<=nr;i++)
        printf("%d %d\n",rr[i].l,rr[i].r);
        */flag=1;
        while(!q.empty())q.pop();
        q.push(ll[1].r);
        for(i=2;i<=nl;i++)
        {
            while(!q.empty()&&ll[i].r>q.top())
            {
                if(ll[i].l<q.top())
                {
                    flag=0;
                    break;
                }
                q.pop();
            }
            q.push(ll[i].r);
        }

        while(!q.empty())q.pop();
        q.push(rr[1].r);
        for(i=2;i<=nr;i++)
        {
            while(!q.empty()&&rr[i].r>q.top())
            {
                if(rr[i].l<q.top())
                {
                    flag=0;
                    break;
                }
                q.pop();
            }
            q.push(rr[i].r);
        }
        if(flag)printf("Yes\n");else printf("No\n");
    }
    return 0;
}
/*
7
2 7 6 3 4 5 1
*/