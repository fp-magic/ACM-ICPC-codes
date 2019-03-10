#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fr first 
#define sc second 
double sum[1000000],lazy[1000000];
int ll,rr;
double xx;
void build(int pl,int pr,int x)
{
    if(pl==pr)sum[x]=1.0;
    else
    {
        int mid=(pl+pr)/2;
        build(pl,mid,2*x);
        build(mid+1,pr,2*x+1);
        sum[x]=sum[2*x]+sum[2*x+1];
    }
}
void pushdown(int pl,int pr,int x)
{
    int m=(pl+pr)/2;
    lazy[2*x]*=lazy[x];lazy[2*x+1]*=lazy[x];
    sum[2*x+1]*=lazy[x];
    sum[2*x]*=lazy[x];
    lazy[x]=0;
}
void change(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)
    {
        lazy[x]*=xx;sum[x]*=xx;
    }
    else
    {
        pushdown(pl,pr,x);
        int m=(pl+pr)/2;
        if(ll<=m)change(pl,m,2*x);
        if(rr>=m+1)change(m+1,pr,2*x+1);
        sum[x]=sum[2*x]+sum[2*x+1];
    }
}
double findsum(int pl,int pr,int x)
{
    if(pl>=ll&&pr<=rr)return(sum[x]);
    else
    {
        int m=(pl+pr)/2;double ans=0;
        if(lazy[x]!=0)pushdown(pl,pr,x);
        if(ll<=m)ans+=findsum(pl,m,2*x);
        if(rr>=m+1)ans+=findsum(m+1,pr,2*x+1);
        return ans;
    }
}
pair<int, double>a[100005];
pair<int,int> b[100005];
map<int,int>mp;
int main()
{
    int n,m,i,j,k,tt;
    double ans;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        build(1,n,1);
        for(i=1;i<=n;i++)
            scanf("%d%lf",&a[i].fr,&a[i].sc),b[i].fr=a[i].fr,b[i].sc=i;
        sort(b+1,b+n+1);
        b[0].fr=0;b[n+1].fr=1e9+7;
        for(i=1;i<=n;i++)
        {
            if(b[i].fr!=b[i-1].fr)
            {
                k=b[i].fr;
                b[i].fr=b[i-1].fr+1;
                a[b[i].sc].fr=b[i].fr;
                while(b[i+1].fr==k)
                {
                    i++;
                    b[i].fr=b[i-1].fr;
                    a[b[i].sc].fr=b[i].fr;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            ll=a[i].fr;
            rr=a[i].fr;
            printf("%.5lf\n",findsum(1,n,1));
            ans+=findsum(1,n,1);
            ll=1;
            rr=a[i].fr;
            xx=1.0-a[i].sc;
            change(1,n,1);
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
