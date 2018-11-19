#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,d,i,j,k,s,t;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    s=(int)(sqrt(a*2))+1;
    t=(int)(sqrt(d*2))+1;
    if(s*(s-1)/2!=a||t*(t-1)/2!=d)
    {
        printf("impossible\n");
        return 0;
    }
    if(b==0&&c==0)
    {
        if(a==0&&d==0)printf("1");
        else if(a==0)for(i=1;i<=t;i++)printf("1");
        else if(d==0)for(i=1;i<=s;i++)printf("0");
        else printf("impossible");
        printf("\n");
        return 0;
    }
    if(b+c!=s*t)
    {
        printf("impossible\n");
        return 0;
    }
    //printf("%d %d\n",s,t);
    for(i=1;i<=b/t;i++)
        printf("0");
    for(j=1;j<=t-b%t;j++)
        printf("1");
    if(b/t!=s)printf("0");
    for(j=t-b%t+1;j<=t;j++)
        printf("1");
    for(i=b/t+2;i<=s;i++)
        printf("0");
    return 0;
}