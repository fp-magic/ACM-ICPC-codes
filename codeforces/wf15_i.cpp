#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define mkp make_pair
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
vector<pair<double,int> >a;
int main()
{
    int n,m,i,j,k,t1,t2,w,l,p;
    double u,v,s,t;
    char ch;
    scanf("%d%d%lf%lf%d%d",&n,&w,&u,&v,&t1,&t2);
    a.clear();
    a.pb(mkp(t1,0));a.pb(mkp(t2,0));
    rep(i,1,n){
        getchar();
        scanf("%c",&ch);
        scanf("%d",&m);
        s=(double)(w*i)/v;
        t=(double)(w*(i-1))/v;
        //printf("%f %f\n",s,t);
        rep(j,1,m){
            scanf("%d%d",&l,&p);
            if(ch=='W')p=-p;
            a.pb(mkp(-p/u-s,1));
            a.pb(mkp(-(p-l)/u-t,-1));
        }
    }
    sort(a.begin(),a.end());
    s=0;k=0;
    rep(i,0,a.size()-2){
        k+=a[i].second;
        if(a[i].first<t2&&a[i].first>=t1&&k==0)
            s=max(s,a[i+1].first-a[i].first);
    }
    printf("%.6f\n",s);
    return 0;
}