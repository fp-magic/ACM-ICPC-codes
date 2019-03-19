#include<cstring>
#include<vector>
#include<cstdio>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
int a[500005],f[500005],g[500005],now;
int main()
{
    int n,m,i,j,k,s,t,bk,l,r;
    scanf("%d%d%d%d",&m,&k,&n,&s);
    for(i=1;i<=m;++i)scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    for(i=1;i<=s;++i)scanf("%d",&t),f[t]++;
    bk=m-k*n;
    l=1;r=0;now=0;
    memset(g,0,sizeof(g));
    t=-1;
    for(i=1;i<=n;++i){
       while(r<i*k+bk){
            r++;
            g[a[r]]++;
            if(f[a[r]]>=g[a[r]])now++;
       }
       if(now==s){
           t=i;
           break;
       } 
       while(l<i*k){
           if(f[a[l]]>=g[a[l]])now--;
           g[a[l]]--;
           l++;
       }
    }
    if(t==-1)
        printf("-1\n");
    else{
        printf("%d\n",bk);
        memset(g,0,sizeof(g));
        for(i=(t-1)*k+1,j=0;i<=t*k+bk&&j<bk;++i){
            g[a[i]]++;
            if(g[a[i]]>f[a[i]])printf("%d ",i),j++;
        }
        printf("\n");
    }
    return 0;
}