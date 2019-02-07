#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi = acos(-1.0);
double r[10005], x[10005], y[10005], z[10005];
int main()
{
    int n, m, i, j, k;
    double s, t, ll, rr, mid, v, pre, nowv, len;
    scanf("%d%lf", &n, &s);
    v = 1e15;
    for (i = 1; i <= n; i++) {
        scanf("%lf%lf%lf%lf", &r[i], &x[i], &y[i], &z[i]);
        v -= 4.0 / 3.0 * pi * r[i] * r[i] * r[i];
    }
    pre = 0;
    for (i = 1; i <= s; i++) {
        nowv = v / s * ((double)i);
        ll = 0.0;
        rr = 100000.0;
        while ((fabs(ll - rr) > 1e-8)) {
            mid = (ll + rr) / 2.0;
            t = ((double)1e10) * mid;
            for (j = 1; j <= n; j++) {
                len = max(0.0, min(r[j] * 2.0, mid - z[j] + r[j]));
                //printf("%.2f %.2f\n",len,pi * len * len * (r[j] - len / 3.0));
                t -= pi * len * len * (r[j] - len / 3.0);
            }//printf("%.2f %.2f %.2f\n",mid,t,nowv);
            if (t <= nowv)
                ll = mid;
            else
                rr = mid;
        }
        printf("%.8f\n", (rr - pre)/1000.0);
        pre = rr;
    }
    return 0;
}