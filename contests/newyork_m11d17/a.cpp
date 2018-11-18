#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
/*
利用欧拉函数的性质的一道题，表面挺麻烦，推出公式就好做了
*/
const ll mod=1e9+7;
map<ll,ll>f;
map<ll,ll>::iterator it;
ll m=110000,phi[110005],prime[110005],sum[110005],tot;
bool np[110005];
void Get_phi()
{
    ll i,j;
    phi[1] = sum[1] = 1;
    for(i = 2 ; i <= m ; i ++ )
    {
        if(!np[i]) phi[i] = i - 1 , prime[++tot] = i;
        for(j = 1 ; j <= tot && i * prime[j] <= m ; j ++ )
        {
            np[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
        sum[i]=sum[i-1]+phi[i];
    }
}
int main()
{
    ll n,i,j,k,s,t,q,tt,ans=0;
    Get_phi();
    scanf("%lld",&tt);
    while(tt--)
    {
        scanf("%lld %lld",&s,&t);
        printf("%lld %lld\n",s,sum[t]+1);
    }
    return 0;
}