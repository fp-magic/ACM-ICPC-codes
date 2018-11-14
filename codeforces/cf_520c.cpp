#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long pw[1000005];
char ch[1000005];
int pl[1000005],pr[1000005];
const long long mod=1e9+7;
int main()
{
    long long n,q,m,i,j,k,l,r,s,t;
    scanf("%I64d%I64d",&n,&q);
    l=r=0;
    scanf("%s",ch+1);
    memset(pl,0,sizeof(pl));
    memset(pr,0,sizeof(pr));
    for(i=1;i<=n;i++)
    {
        if(ch[i]=='1')pl[i]=pl[i-1]+1,pr[i]=pr[i-1];
        else pl[i]=pl[i-1],pr[i]=pr[i-1]+1;
    }
    pw[0]=1;for(i=1;i<1000003;i++)pw[i]=(pw[i-1]*2)%mod;
    while(q--)
    {
        scanf("%I64d%I64d",&s,&t);
        l=pl[t]-pl[s-1];
        r=pr[t]-pr[s-1];
        //printf("%I64d %I64d\n",l,r);
        s=(pw[l]-1+mod)%mod;
        t=s*((pw[r]-1+mod)%mod)%mod;
        printf("%I64d\n",(s+t)%mod);
    }
    return 0;
}