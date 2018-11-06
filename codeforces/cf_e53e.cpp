#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define ll long long
#define ull unsigned long long
using namespace std;
/*
很普通的套板子的数位dp题目，麻烦的地方在于要分别算数量和总和。
注意要在计算的时候及时取模=
*/
const ll mod=998244353;
ll dp[20][1024][12],sum[20][1024][12];
int a[20];
ll pw10[19];
ll dfsnum(int pos,int zero,int sta,int limit,int rnum)
{
    if(rnum<0)return 0;
    if(pos==-1)return 1;
    if(!limit&&dp[pos][sta][rnum]!=-1)
        return dp[pos][sta][rnum];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if(i==0&&!zero)
            ans+=dfsnum(pos-1,zero,sta,limit&&i==a[pos],rnum);
        else
        if(((1<<i)&sta)==0)
            ans+=dfsnum(pos-1,zero|1,sta|(1<<i),limit&&i==a[pos],rnum-1);
        else
            ans+=dfsnum(pos-1,zero|1,sta,limit&&i==a[pos],rnum);
        ans%=mod;
    }
    ans%=mod;
    if(!limit)
        dp[pos][sta][rnum]=ans;
    return ans;
}
ll dfssum(int pos,int zero,int sta,int limit,int rnum)
{
    if(rnum<0)return 0;
    if(pos==-1)return 0;
    if(!limit&&sum[pos][sta][rnum]!=-1)
        return sum[pos][sta][rnum];
    int up=limit?a[pos]:9;
    ll ans=0,tmp;
    for(int i=0;i<=up;i++)
    {
        if(i==0&&!zero)
            ans+=dfssum(pos-1,zero,sta,limit&&i==a[pos],rnum);
        else
        if(((1<<i)&sta)==0)
        {
            tmp=dfsnum(pos-1,zero|1,sta|(1<<i),limit&&i==a[pos],rnum-1);
            ans+=tmp*i*pw10[pos]%mod+dfssum(pos-1,zero|1,sta|(1<<i),limit&&i==a[pos],rnum-1);
        }else
        {
            tmp=dfsnum(pos-1,zero|1,sta,limit&&i==a[pos],rnum);
            ans+=tmp*i*pw10[pos]%mod+dfssum(pos-1,zero|1,sta,limit&&i==a[pos],rnum);
        }
        ans%=mod;
    }
    ans%=mod;
    if(!limit)
        sum[pos][sta][rnum]=ans;
    return ans;
}
ll solve(ll x,int rnum)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfssum(pos-1,0,0,1,rnum);
}
int main()
{
    ll tt,n,m,i,j,k,s,t,l,r;
    int rnum;
    memset(dp,255,sizeof(dp));
    memset(sum,255,sizeof(sum));
    pw10[0]=1;
    for(i=1;i<=18;i++)pw10[i]=(pw10[i-1]*10)%mod;
    scanf("%I64d%I64d%d",&l,&r,&rnum); 
    printf("%I64d\n",(mod+solve(r,rnum)-solve(l-1,rnum))%mod);
    return 0;
}
