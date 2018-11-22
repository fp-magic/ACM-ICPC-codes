#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
int a[1000][1000],n,f[10];
//__int128 q,w,e,r,z,x,c;
unsigned long long ans;
void dfs(int x,int y,int step)
{
    if(a[x][y]==0)ans++;
    a[x][y]=1;
    if(step<=0)return;
    dfs(x+2,y+1,step-1);
    dfs(x+1,y+2,step-1);
    dfs(x-1,y+2,step-1);
    dfs(x-2,y+1,step-1);
    dfs(x+2,y-1,step-1);
    dfs(x+1,y-2,step-1);
    dfs(x-1,y-2,step-1);
    dfs(x-2,y-1,step-1);
}
int main()
{
    int tt,m,i,j,k,s,t,step=0;
    for(n=0;n<=7;n++)
    {
        memset(a,0,sizeof(a));
        ans=0;
        dfs(500,500,n);
        f[n]=ans;
    }
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        if(n<8)ans=f[n];
        else
        {
            ans=(unsigned long long)649+(204*(n-7))+14*(n-7)*(n-8);
        }
        printf("Case #%d: %llu\n",++step,ans);
    }
    return 0;
}