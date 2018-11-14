#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int tt,n,m,i,j;
    double k,s,t;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%lf",&k);
        if(k<=3&&k>=1)printf("N\n");
        else
        {
            s=sqrt(k*k-4*k);
            printf("Y %.10lf %.10lf\n",(k+s)/2.0,(k-s)/2.0);
        }
    }
    return 0;
}