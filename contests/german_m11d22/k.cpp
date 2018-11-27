#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct node
{
    char a[10];
    int c;
    bool operator < (const node &r)const
    {
        return c<r.c;
    }
}a[10005];
int main()
{
    int n,d,m,i,j,k,s,t;
    scanf("%d%d%d",&n,&d,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%s %d",a[i].a,&a[i].c);
    }
    sort(a+1,a+n+1);
    s=0;
    for(i=n;i>=n-k+1;i--)
    {
        s=s+a[i].c;
        if(s>=d)break;
    }
    if(s>=d)
    {
        printf("%d\n",k);
        for(i=n;i>=n-k+1;i--)
            printf("%s, YOU ARE FIRED!\n",a[i].a);
    }else
        printf("impossible\n");
    return 0;
}
