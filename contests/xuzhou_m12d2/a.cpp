#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const unsigned long long mod=1e9+7;
int p[100005];
struct node{
    int u,v;
    unsigned long long w;
}a[100005];
int cmp(node l,node r){
    return l.w<r.w;
}
int fin(int x){
    if(p[x]!=x)p[x]=fin(p[x]);return p[x];
}
int unio(int x,int y){
    int px=fin(x),py=fin(y);
    p[px]=py;
}
unsigned long long k1,k2;
unsigned long long xorS(){
    unsigned long long k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
int n,m;
void gen(){
    scanf("%d%d%I64u%I64u",&n,&m,&k1,&k2);
    for(int i=1;i<=m;++i){
        a[i].u=xorS()%n+1;
        a[i].v=xorS()%n+1;
        a[i].w=xorS();
    }
}
int main(){
    int tt,s,i,j,k;
    unsigned long long ans;
    scanf("%d",&tt);
    while(tt--){
        gen();
        ans=0;
        sort(a+1,a+m+1,cmp);
        for(i=1;i<=n;i++)p[i]=i;
        s=0;
        for(i=1;i<=m;i++)
        if(fin(a[i].u)!=fin(a[i].v)){
            ans=(ans+a[i].w)%mod;
            unio(a[i].u,a[i].v);
            //printf("%d %d %llu\n",a[i].u,a[i].v,a[i].w);
            s++;
        }
        if(s==n-1)
            printf("%I64u\n",ans);
        else
            printf("0\n");
    }
    return 0;
}