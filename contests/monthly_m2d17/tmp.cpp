#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=200010;
const LL p = 100000007700000049ll;
const LL mod[2] = {1000000007ll,100000007ll };
LL fac[2][maxn],odd[maxn],M,Mod,now;
LL mul(LL x,LL y,LL pp)
{
    LL res=0;
    while(y){
        if(y&1) res=(res+x)%pp;y>>=1;x=(x+x)%pp;
    }return res%pp;
}
LL f_pow(LL a,LL x)
{
    LL res=1; a%=Mod;
    while(x){  if(x&1) res=mul(res,a%Mod,Mod);a=mul(a,a,Mod); x>>=1; }return res;
}
LL C(LL n,LL m)
{
    if(m>n) return 0; return mul(fac[now][n],f_pow(fac[now][m]*fac[now][n-m]%Mod,Mod-2),Mod);
}
LL Lucas(LL n,LL m)
{
    if(m==0) return 1;  return mul(C(n%Mod,m%Mod),Lucas(n/Mod,m/Mod),Mod); 
}
void factorial()
{
    fac[0][0]=1;  for(int i=1;i<maxn;i++) fac[0][i]=mul(fac[0][i-1],i,mod[0]);
    fac[1][0]=1;  for(int i=1;i<maxn;i++) fac[1][i]=mul(fac[1][i-1],i,mod[1]);
}
void China(int k)
{
    LL ans=0;
    for(int i=0;i<2;i++){
        Mod=mod[i];
        ans=ans+mul(mul(M/mod[i],f_pow(M/mod[i],mod[i]-2),M),odd[i],M);
    }printf("%lld\n",(ans+M)%M);
}
int main()
{    
    LL T,n,m,k;
    factorial();
    scanf("%lld",&T);
    while(T--){
        M=1;
        scanf("%lld%lld",&n,&m);
        for(now=0;now<2;now++){
            Mod=mod[now];M*=mod[now];
            odd[now]=Lucas(n,m)%Mod;
        }
        China(k);
    }return 0;
}