#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double a[100005];
long long cnt(double x,int num){
    long long ans=0;
    for(int i=0;i<num;++i)
        ans+=(int)(floor(a[i]/x));
    return ans;
}
int main()
{
    int n,m,i,j;
    double k,s,t,l,r,mid;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)
        scanf("%lf",&a[i]);
    l=1e-10;r=1e9;
    while(fabs(l-r)>1e-4){
        mid=(l+r)/2.0;
        if(cnt(mid,n)>=(long long)m)l=mid;
        else r=mid;
    }
    printf("%.2f\n",mid);
    return 0;
}