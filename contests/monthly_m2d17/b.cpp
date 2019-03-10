#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
int zs[1000005];
int num[1000005],tot,a[1000005];
void init()
{
    memset(zs,0,sizeof(zs));
    for(int i=2;i<=1000000;i++)
    if(!zs[i])
        for(int j=i+i;j<=1000005;j+=i)
            zs[j]=1;
    memset(num,0,sizeof(num));
    num[2]=1;
    tot=0;
    for(int i=2;i<=1000000;i++)
    if(!zs[i])
        a[++tot]=i;
    for(int i=3;i<=1000000;i++)
        num[i]=1-zs[i];
    for(int i=1;i<tot&&a[i]*a[i]<=1000000;i++)
    {
        for(int j=i+1;a[i]*a[j]<=1000000;j++)
            num[a[i]*a[j]]++;
    }
    for(int i=1;i<=1000000;i++)
        num[i]+=num[i-1];
}
int main()
{
    int tt,n,m,i,j,k,s,t;
    init();
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        printf("%d\n",n-num[n]-1);
    }
    return 0;
}