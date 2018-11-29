#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int nxt[100005];
vector<int>a[100005];
long long sum[100005];
int main()
{
    int n,m,i,j,k,pre;
    long long s,t,ans;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)a[i].clear();
    for(i=0;i<m;i++)nxt[i]=i+1;
    nxt[m]=-1;
    memset(sum,0,sizeof(sum));
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&j,&k);
        a[j].push_back(k);
    }
    for(i=1;i<=m;i++)
    {
        sort(a[i].begin(),a[i].end());
        //for(j=0;j<a[i].size();j++)printf("%d ",a[i][j]);printf("\n");
    }
    ans=0;s=0;
    for(i=1;i<=n;i++)
    {
        pre=0;
        for(j=nxt[0];j!=-1;j=nxt[j])
        {
            if(a[j].size()<i||sum[j]+a[j][a[j].size()-i]<=0)
            {
                s-=sum[j];
                nxt[pre]=nxt[j];
                continue;
            }
            s+=a[j][a[j].size()-i];
            sum[j]+=a[j][a[j].size()-i];
            pre=j;
        }//printf("%lld\n",s);
        ans=max(ans,s);
    }
    printf("%I64d\n",ans);
    return 0;
}