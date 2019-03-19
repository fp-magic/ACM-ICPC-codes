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
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
struct node{
    map<int,int>nxt;
    int x;
};
node a[4000005];
vector<int>b[5005];
int f[5005];
int now;
char c[5005];
int main()
{
    int n,m,i,j,k,s,t,p,q;
    scanf("%d%d%d",&n,&p,&q);
    getchar();
    scanf("%s",c);
    s=strlen(c);
    for(i=0;i<4000005;++i){
        a[i].nxt.clear();
        a[i].x=-1;
    }
    now=1;
    for(i=s-1;i>=0;--i){
        t=0;
        for(j=i;j>=0;--j){
            if(a[t].nxt.count(c[j]-'a')==0){
                a[t].nxt.insert(make_pair(c[j]-'a',now++));
                t=now-1;
            }
            else
                t=a[t].nxt[c[j]-'a'];
            if(a[t].x==-1)
                a[t].x=i;
            else
                a[t].x=min(a[t].x,i);             
        }
    }
    //for(i=0;i<now;++i)printf("%d ",a[i].x);printf("\n");
    for(i=s-1;i>=0;--i){
        t=0;
        b[i].clear();
        for(j=i;j>=1;--j){
            t=a[t].nxt[c[j]-'a'];
            //printf("%d %d: %d\n",i,j,a[t].x);
            if(a[t].x<j){
                b[i].push_back(j-1);
                //printf("%d %d\n",i,j-1);
            }
        }
    }
    f[0]=p;
    for(i=1;i<s;++i)
    {
        f[i]=f[i-1]+p;
        for(j=0;j<b[i].size();++j)
            f[i]=min(f[i],f[b[i][j]]+q);
    }
    printf("%d\n",f[s-1]);
    return 0;
}