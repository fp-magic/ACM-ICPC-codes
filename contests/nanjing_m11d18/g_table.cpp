#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<double>x,y;
int equ(double l,double r)
{
    if(fabs(l-r)<=0.0001)return 1;
    return 0;
}
int main()
{
    long long tt,n,m,i,j,ii,ans,mod=1e9+7;
    double k,s,t,u;
    k=sqrt(3)/2.0;
    x.clear();
    y.clear();
    x.push_back(0.0);
    y.push_back(0.0);
    for(n=1;n<=10;n++)
    {
        for(i=0;i<=n;i++)
        {
            x.push_back(n-0.5*(double)i);
            y.push_back(k*(double)i);
        }
        ans=0;
        for(i=0;i<x.size();i++)
            for(j=i+1;j<x.size();j++)
                for(ii=j+1;ii<x.size();ii++)
                {
                    s=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    t=(x[ii]-x[j])*(x[ii]-x[j])+(y[ii]-y[j])*(y[ii]-y[j]);
                    u=(x[i]-x[ii])*(x[i]-x[ii])+(y[i]-y[ii])*(y[i]-y[ii]);
                    //if(n<=4)printf("%.4lf %.4lf %.4lf\n",s,t,u);
                    if(equ(s,t)&&equ(s,u)&&equ(t,u))
                    {
                        ans++;
                    }
                }
        printf("%lld: %lld\n",n,ans);
    }
    return 0;
}