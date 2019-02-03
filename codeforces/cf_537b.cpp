#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100005];
int main()
{
    int n,m,i,j,k;
    long long s,num;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    s=0;
    num=0;
    if(m<=n-1)
    {
        num=n;
        k=m;
        for(i=1;i<=m;i++)
        {
            if(a[i]==a[n])break;
            k--;
        }
        num=n-i+1;
        //printf("%d\n",num);
        for(i=n-num+1;i<=n;i++)
            s+=(long long)a[i];
        s+=k;
        printf("%.8f\n",(double)s/(double)num);
    }else
    {
        s=min(a[n]+k,a[n]+m-(n-1));
        printf("%.8f\n",(double)s);
    }
    return 0;
}