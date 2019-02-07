#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
ll f[100005], g[100005], fac[100005], inv[100005];
ll ans[55][55], num[55];
char c[100005];
ll pmod(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1ll)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2ll;
    }
    return res;
}
void amod(ll& a, ll b)
{
    a = (a + b + mod) % mod;
}
void dmod(ll& a, ll b)
{
    a = (a - b + mod) % mod;
}
int tag(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a';
    else
        return ch - 'A' + 26;
}
int main()
{
    ll n, m, i, j, k, s, t;
    scanf("%s", c);
    n = strlen(c);
    memset(num, 0, sizeof(num));
    for (i = 0; i < n; i++)
        num[tag(c[i])]++;
    fac[0] = 1;
    for (i = 1; i < 100005; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    inv[n] = pmod(fac[n], mod - 2);
    for (i = n - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (i = 0; i < 52; i++) {
        for (j = n / 2; j >= num[i]; j--)
            if (num[i])
                amod(f[j], f[j - num[i]]);
    }
    for (i = 0; i < 52; i++)
        ans[i][i] = f[n / 2];

    s = fac[n / 2] * fac[n / 2] % mod;
    for (i = 0; i < 52; i++)
        s = (s * inv[num[i]]) % mod;    
    for (i = 0; i < 52; i++) {
        for (j = 0; j <= n / 2; j++)
            g[j] = f[j];
        for (j = num[i]; j <= n / 2; j++)
            dmod(g[j], g[j - num[i]]);
        for (j = i + 1; j < 52; j++) {
            if(!num[j])continue;
            for (k = num[j]; k <= n / 2; k++)
                dmod(g[k], g[k - num[j]]);
            ans[i][j] = ans[j][i] = (g[n / 2] * 2LL) % mod;
            //printf("%I64d %I64d ? %I64d %I64d: %I64d\n",num[i],num[j],i,j,g[n/2]);
            for (k = n / 2; k >= num[j]; k--)
                amod(g[k], g[k - num[j]]);
        }
    }
    //printf("%I64d %I64d %I64d\n", ans[0][0], ans[0][1], ans[1][1]);
    scanf("%I64d", &m);
    while (m--) {
        scanf("%I64d%I64d", &i, &j);
        //printf("%I64d %I64d %s\n", i, j, c);
        //printf("%c %d %c %d=", c[i - 1], tag(c[i - 1]), c[j - 1], tag(c[j - 1]));
        printf("%I64d\n", s * ans[tag(c[i - 1])][tag(c[j - 1])] % mod);
    }
    return 0;
}