#include <bits/stdc++.h>
using namespace std;
#define rep(i, st, en) for (i = st; i <= en; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
ll fmod(ll b, ll exp)
{
    ll res = 1;
    while (exp) {
        if (exp & 1ll)
            res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2ll;
    }
    return res;
}
ll get(char ch, ll x)
{
    ll ret;
    printf("%c %I64d\n", ch, x);
    fflush(stdout);
    scanf("%I64d", &ret);
    return ret;
}
ll a[100], flag[1000005];
int main()
{
    ll n, m, i, j, k, s, t, num, gap, l, r, mid;
    scanf("%I64d", &n);
    memset(flag, 0, sizeof(flag));
    srand((unsigned)time(NULL));
    m = min(n, 39LL);
    for (i = 1; i <= m; i++) {
        do {
            t = 0;
            for(j=1;j<=103;j++)t+=rand();
            t=t%n+1;
        } while (flag[t]);
        a[i] = get('?', t);
        flag[t] = 1;
    }
    sort(a + 1, a + m + 1);
    gap = a[2] - a[1];
    for (i = 1; i < m; i++)
        for (j = i + 1; j <= m; j++)
            gap = __gcd(gap, a[j] - a[i]);
    l = (a[m] - a[1]) / gap;
    r = min(n - 1,((ll)1e9-a[1])/gap);
    while (l < r) {
        mid = (l + r + 1) / 2;
        t = get('>', a[1] + mid * gap - 1);
        if (t == 1)
            l = mid;
        else
            r = mid - 1;
    }
    printf("! %I64d %I64d\n", a[1] - (n-l-1) * gap, gap);
    return 0;
}