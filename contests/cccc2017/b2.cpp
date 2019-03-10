#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int a[100005],b[100005],c[100005];
void output(int x)
{
    if(x<10000)printf("0");
    if(x<1000)printf("0");
    if(x<100)printf("0");
    if(x<10)printf("0");
    printf("%d",x);
}
int main()
{
    int root,i,j,k,s,t,n;
    scanf("%d%d",&root,&n);
    memset(a,255,sizeof(a));
    memset(b,255,sizeof(b));
    memset(c,255,sizeof(c));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        scanf("%d%d",&a[k],&b[k]);
    }
    s=root;
    for(i=1;i<=n;i++)
    {
        c[i]=s;
        if(s!=-1)s=b[s];
    }
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            output(c[n-i/2]);
            printf(" %d ",a[c[n-i/2]]);
            if(i==n)printf("-1");else output(c[i/2+1]);
            printf("\n");
            //printf("%d %d %5d\n",c[n-i/2],a[c[n-i/2]],c[i/2+1]);
        }else
        {
            output(c[i/2]);
            printf(" %d ",a[c[i/2]]);
            if(i==n)printf("-1");else output(c[n-i/2]);
            printf("\n");
            //printf("%5d %d %5d\n",c[i/2],a[c[i/2]],c[n-i/2]);
        }
    }
    return 0;
}