#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int n,m,q,i,j,k,s,t;
    for(n=2;n<=10000;n++)
    {
        s=1;
        for(i=1;i<=n-1;i++)
        if(__gcd(n^i,n&i)>__gcd(n^s,n&s))s=i;
        if(n%512==511)printf("%d: %d %d\n",n,s,__gcd(n^s,n&s));
    }
    return 0;
}