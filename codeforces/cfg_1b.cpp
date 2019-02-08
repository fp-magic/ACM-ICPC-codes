#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100005];
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(i!=1)
        {
            a[i-1]=t-s-1;
        }
        s=t;
    }
    sort(a+1,a+n);
    s=n;
    i=1;
    for(i=1;i<=n-k;i++)s+=a[i];
    printf("%d\n",s);
    return 0;
}