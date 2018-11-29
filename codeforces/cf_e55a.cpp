#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,x,y,d,i,j,k,s,t,tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&d);
        if(abs(y-x)%d==0)
        {
            printf("%d\n",abs(y-x)/d);
            continue;
        }else
        {
            s=2000000000;
            if((y-1)%d==0)
                s=min(s,(y-1)/d+(x-1+d-1)/d);
            if((n-y)%d==0)
                s=min(s,(n-y)/d+(n-x+d-1)/d);
            if(s==2000000000)printf("-1\n");else printf("%d\n",s);
            continue;
        }
    }
    return 0;
}