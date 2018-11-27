#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int f[300005];
int num[300005];
int main()
{
    int n,m,i,j,k,s,t;
    memset(f,0,sizeof(f));
    memset(num,0,sizeof(num));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(i=m+1;i<=n;i++)
    {
        f[i]=max(f[i],f[i-1]);
        f[i]=max(f[i],f[i-m]+num[i]);
    }
    printf("%d\n",f[n]);
    return 0;
}