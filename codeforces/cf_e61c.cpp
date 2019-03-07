#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
int a[5005],l[5005],r[5005],f[5005],g[5005];
int cnt(int x,int y){return f[y]-f[x-1];}
int dnt(int x,int y){return g[y]-g[x-1];}
int main()
{
    int n,m,q,i,j,k,s,t,ii,jj;
    scanf("%d%d",&n,&q);
    memset(a,0,sizeof(a));
    rep(i,1,q){
        scanf("%d%d",&l[i],&r[i]);
        rep(j,l[i],r[i])
            a[j]++;
    }
    k=0;
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    rep(i,1,n){
        if(a[i]==1)f[i]=1;
        if(a[i]==2)g[i]=1;
        if(a[i]>0)k++;
    }
    rep(i,2,n)f[i]+=f[i-1],g[i]+=g[i-1];
    s=n;
    //printf("==%d==\n",k);
    rep(i,1,q)rep(j,i+1,q)
    {
        t=0;
        if(r[i]<l[j]||r[j]<l[i])
            t=cnt(l[i],r[i])+cnt(l[j],r[j]);
        else
            t=cnt(min(l[i],l[j]),max(r[i],r[j]))+dnt(max(l[i],l[j]),min(r[i],r[j]));
        s=min(s,t);
        //printf("%d %d:%d\n",i,j,t);
    }
    printf("%d\n",k-s);
    return 0;
}