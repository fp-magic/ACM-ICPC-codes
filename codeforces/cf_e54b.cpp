#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long prime[100005],tot,isprime[100005];
void init()
{
    memset(isprime,0,sizeof(isprime));
    tot=0;
    for(int i=2;i<100005;i++)
        if(isprime[i]==0)
        {
            prime[++tot]=i;
            for(int j=i+i;j<100005;j+=i)
                isprime[j]=1;
        }
}
long long find(long long x)
{
    for(int i=1;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)return prime[i];
    }
    return x;
}
int main()
{
    long long n,m,i,j,k,s,t;
    init();
    scanf("%I64d",&n);
    if(n%2==0)
    {
        s=n/2;
    }else
    {
        t=find(n);//printf("=%I64d\n",t);
        s=1+(n-t)/2;
    }
    printf("%I64d\n",s);
    return 0;
}