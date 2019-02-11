#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
ll fmod(ll b,ll exp){
    ll res =1;
    while(exp){if(exp&1ll)res=(res*b)%mod;
        b =(b*b)%mod;exp/=2ll;
    }
    return res;
}
int main()
{
    int n,m,i,j,k,s,t,x,y,z,a,b,c;
    scanf("%d%d%d",&x,&y,&z);
    scanf("%d%d%d",&a,&b,&c);
    if(a>=x&&(a+b-x)>=y&&(a+b+c-x-y)>=z)
        puts("YES");
    else
        puts("NO");
    return 0;
}