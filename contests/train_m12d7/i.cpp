#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,i,j,k,s,t;
    while(scanf("%lld",&n)!=EOF)
    {
        s=1;
        for(i=1;i<=n;i++)
            s=s*8;
        printf("%lld\n",s);
    }
    return 0;
}