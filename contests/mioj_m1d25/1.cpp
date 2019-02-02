#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
int main()
{
    long long n,m,i,j,k,s,t,l;
    scanf("%lld%lld",&n,&l);
    if((n-l)%2==0&&l%2==0)
        s=n-l;
    else
    if((n-l)%2==0&&l%2==1)
        s=min(n-l,l);
    else
    if((n-l)%2==1&&l%2==0)
        s=-1;
    else
        s=l;
    if(s==-1)
        printf("Impossible\n");
    else
        printf("%lld\n",s);
    return 0;
}