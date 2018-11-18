#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int prim[1000005],zs[1000005],num[1000005],tot,bg[1000005];
vector<int>a[1000005];
long long pw[1000005];
void init()
{
    memset(zs,0,sizeof(zs));
    memset(bg,127,sizeof(bg));
    bg[1]=1;
    tot=0;
    for(int i=2;i<1000005;i++)
    if(zs[i]==0)
    {   
        prim[++tot]=i;
        num[i]=tot;
        bg[i]=tot;
        if(i<=1001)
        for(int j=i*i;j<1000005;j+=i)
            zs[j]=1,bg[j]=min(bg[j],tot);
    }
    for(long long i=0;i<1000005;i++)
        pw[i]=i*(i+1)/2;
    //for(int i=1;i<=10;i++)printf("%d ",prim[i]);printf("\n");
}
int main()
{
    init();
    int n,i,j,k,t;
    long long ans,s;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=tot;i++)a[i].clear();
        for(j=1;j<=n;j++)
        {
            scanf("%d",&k);//printf("=%d\n",bg[k]);
            for(i=bg[k];i<=tot&&prim[i]<=k;i++)
            {
                if(k%prim[i]==0)
                {
                    while(k%prim[i]==0)
                    {
                        k/=prim[i];
                    }
                    a[i].push_back(j);
                    if(k>=2&&!zs[k])
                    {//printf("%d %d %d\n",k,num[k],j);
                        a[num[k]].push_back(j);
                        break;
                    }
                }
            }
        }//printf("?");
        ans=0;
        for(i=1;i<=tot;i++)
        if(a[i].size())
        {//printf("%d: ",prim[i]);for(j=0;j<a[i].size();j++)printf("%d ",a[i][j]);printf("\n");
            s=pw[n]-pw[a[i][0]-1]-pw[n-a[i][a[i].size()-1]];
            for(j=0;j<a[i].size()-1;j++)
                s-=pw[a[i][j+1]-a[i][j]-1];
            ans+=s;
            //printf("%lld\n",s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}