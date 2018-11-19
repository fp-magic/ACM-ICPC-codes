#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[400];
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    t=0;
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        a[k]++;
    }
    s=0;k=0;
    for(i=1;i<=365;i++)
    {
        if(a[i]==1)t++;
        if(s+t>=20)
        {
            t=0;
            s=0;
            k++;
        }else
            s+=t;
    }
    if(t!=0)k++;
    printf("%d\n",k);
    return 0;
}