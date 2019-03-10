#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define first fr
#define second sc
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
    char ch[100];
    int n,m,i,j,k,s,t;
    n=93;
    sprintf(ch,"test_%d.txt",n);
    freopen(ch,"w",stdout);
    return 0;
}