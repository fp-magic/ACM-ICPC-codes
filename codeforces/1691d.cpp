#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,t;
int a[maxn],st[maxn];
ll s[maxn],f[18][maxn];
ll query(int l,int r)
{
    int k=log2(r-l+1);
    return max(f[k][l],f[k][r-(1<<k)+1]);
}
bool check()
{
    reverse(a+1,a+n+1),s[n+1]=0;
    for(int i=n;i>=1;i--) s[i]=s[i+1]+a[i],f[0][i]=s[i];
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
    for(int i=1,top=0;i<=n;i++)
    {
        while(top&&a[i]>=a[st[top]]) top--;
        if(query(st[top]+1,i)-s[i+1]>a[i]) return false;
        st[++top]=i;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf(check()&&check()?"YES\n":"NO\n");
    }
    return 0;
}