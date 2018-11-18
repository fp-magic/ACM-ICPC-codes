#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    long long tmp=x;
    long long ret=1;
    while(n)
    {
        if(n&1) ret=ret*tmp%mod;
        tmp=tmp*tmp%mod;
        n>>=1;
    }
    return ret;
}
int main()
{
    long long tt,n,m,i,j,k,s,t,mod=1e9+7;
    scanf("%lld",&tt);
    while(tt--)
    {
        scanf("%lld",&n);
        s=((n+3)*(n+2))%mod;
        s=(s*(n+1))%mod;
        s=(s*n)%mod;
        //printf("=%lld\n",s);
        s=(s*pow_mod(24ll,mod-2,mod))%mod;
        printf("%lld\n",s);
    }
    return 0;
}