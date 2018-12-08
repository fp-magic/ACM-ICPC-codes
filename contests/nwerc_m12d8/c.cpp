#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
vector<int>a[1005];
long double ansx[1005],ansy[1005];
int flag[1005],son[1005];
int n;
unsigned seed;
int dfs(int x){
    if(flag[x])return son[x];
    flag[x]=1;
    shuffle (a[x].begin (), a[x].end (), default_random_engine (seed));
    for(int i=0;i<a[x].size();i++)
    if(!flag[a[x][i]]){
        //if(x==1)printf("%d\n",a[x][i]);
        son[x]+=dfs(a[x][i])+1;
    }
    return son[x];
}
void solve(int x,long double nowx,long double nowy,long double l,long double r){
    if(flag[x])return;
    flag[x]=1;
    ansx[x]=nowx;
    ansy[x]=nowy;
    long double ll,rr;
    ll=l;//printf("%d %f %f %f %f %d\n",x,nowx,nowy,l,r,son[x]);
    for(int i=0;i<a[x].size();i++)
    if(!flag[a[x][i]]){
        rr=ll+(r-l)*(son[a[x][i]]+1)/(son[x]);
        //printf("  %f %f\n",ll,rr);
        solve(a[x][i],nowx+cos((ll+rr)/2.0),nowy+sin((ll+rr)/2.0),ll,rr);
        ll=rr;
    }
}
long double dis(int x,int y){
    return sqrt((ansx[x]-ansx[y])*(ansx[x]-ansx[y])+(ansy[x]-ansy[y])*(ansy[x]-ansy[y]));
}
int main(){
    int i,j,k,s,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        a[i].clear();
    //for(i=2;i<=n;i++){
    //    a[i/2].push_back(i);
    //}
    for(i=1;i<=n-1;i++){
        scanf("%d%d",&s,&t);
        a[s].push_back(t);
        a[t].push_back(s);
    }
    memset(flag,0,sizeof(flag));
    memset(son,0,sizeof(son));
    dfs(1);
    memset(flag,0,sizeof(flag));
    //for(i=1;i<=n;i++)printf("%d ",son[i]);printf("\n");
    seed = chrono::system_clock::now ().time_since_epoch ().count ();
    solve(1,0,0,0,2.0*acos(-1.0));
    for(i=1;i<=n;i++){
        printf("%.8Lf %.8Lf\n",ansx[i],ansy[i]);
    }
    long double tmp=10;
    /*for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            tmp=min(tmp,dis(i,j));
    printf("%.8Lf\n",tmp);*/
    return 0;
}