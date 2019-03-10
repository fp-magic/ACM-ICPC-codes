#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
double a[1000005], b[1000005], c[1000005];
vector<pair<int,double> >ans;
bool bigger(int ad, int bd, double p)
{
    double t;
    while (ad >= 0 && bd >= 0) {
        t=a[ad]-b[bd]*p;
        if(t<=-1e-6)return 0;
        if(t>=1e-6)return 1;
        ad--;bd--;
    }
    return 1;
}
void deccer(int ad, int bd, double p)
{
    double t;
    while (ad >= 0 && bd >= 0) {
        a[ad]-=b[bd]*p;
        ad--;bd--;
    }
}
int main()
{
    int n, m, i, j, k, s, t;
    double l, r, mid;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; i++) {
        scanf("%d", &k);
        scanf("%lf", &a[k]);
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%d", &k);
        scanf("%lf", &b[k]);
    }
    n = 1000000;
    while (a[n] == 0)
        n--;
    m = 1000000;
    while (b[m] == 0)
        m--;
    for (i = n; i >= 0; i--) {
        //printf("%d %d\n",i,m);
        if (!a[i])
            continue;
        if (i < m)
            break;
        l = -1000000000;
        r = 1000000000;
        while (l < r - 1e-8) {
            mid = (l + r) / 2.0;
            if (bigger(i, m, mid))
                l = mid;
            else
                r = mid;
        }
        c[i - m] = mid;
        /*mid=a[i]/c[m];
        for(j=0;j<=m;j++)
        {
            if(a[i]>1e-6&&c[i]>1e-6)ans=min(ans,a[ui]/c[i]);
            if(a[i]<)
        }*/
        deccer(i,m,mid);
    }
    //for(i=5;i>=0;i--)printf("%.2f ",c[i]);
    //printf("\n");
    //for(i=5;i>=0;i--)printf("%.2f ",a[i]);
    //printf("\n");
    ans.clear();
    for(i=n;i>=0;i--)
    {
        if(c[i]>=0.05000000000||c[i]<=-0.05000000000)
            ans.push_back(make_pair(i,c[i]));
    }
    printf("%d",ans.size());
    for(i=0;i<ans.size();i++)
    {
        printf(" %d %.1f",ans[i].first,ans[i].second);
    }
    if(ans.size()==0)printf(" 0 0.0");
    printf("\n");
    ans.clear();
    for(i=n;i>=0;i--)
    {
        if(a[i]>=0.05000000000||a[i]<=-0.05000000000)
            ans.push_back(make_pair(i,a[i]));
    }
    printf("%d",ans.size());
    for(i=0;i<ans.size();i++)
    {
        printf(" %d %.1f",ans[i].first,ans[i].second);
    }
    if(ans.size()==0)printf(" 0 0.0");
    printf("\n");
    return 0;
}