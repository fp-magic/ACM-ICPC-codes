#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int prim[10000],flag[10005],tot;
void init()
{
    memset(flag,0,sizeof(flag));
    tot=0;
    for(int i=2;i<=10003;i++)
    if(flag[i]==0)
    {
        prim[++tot]=i;
        for(int j=i+i;j<=10003;j+=i)
        {
            flag[j]=1;
        }
    }
}
int a[20],b[20];
int main()
{
    int n,m,i,j,k,s,t,num;
    init();
    scanf("%d",&n);
    num=0;
    for(i=1;i<=tot&&prim[i]<=n;i++)
    if(n%prim[i]==0)
    {
        t=0;
        while(n%prim[i]==0)
        {
            t++;
            n/=prim[i];
        }
        a[++num]=t;
        b[num]=prim[i];
        if(n==1)break;
    }
    if(n!=1)
    {
        a[++num]=1;
        b[num]=n;
    }
    t=0;
    for(i=1;i<=num;i++)t=max(t,a[i]);
    for(i=0;i<=20;i++)
    {
        if((1<<i)>=t)break;
    }
    s=i+1;
    t=1;
    for(j=1;j<=num;j++)
    {
        if(a[j]!=(1<<i))t=0;
    }
    s-=t;
    t=1;
    for(i=1;i<=num;i++)t*=b[i];
    printf("%d %d\n",t,s);
    return 0;
}