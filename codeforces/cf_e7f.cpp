#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
/*
朗格朗日插值练习题
*/
const ll mod = 1e9 + 7;
long long qpow(long long a, long long b)
{
    a %= mod, b %= mod;
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll a[1000005];
ll fac[1000005], nfac;
int main()
{
    ll n, k, i, j, s, ans = 0;
    scanf("%I64d%I64d", &n, &k);
    a[0] = 0;
    for (i = 1; i <= k + 2; i++)
        a[i] = (a[i - 1] + qpow(i, k)) % mod;
    fac[0] = 1;
    for (i = 1; i <= k + 2; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    nfac = 1;
    for (i = 1; i <= k + 2; i++)
        nfac = (nfac * (n - i)) % mod;
    if (n <= k + 2)
    {
        printf("%I64d\n", a[n]);
        return 0;
    }
    for (i = 1; i <= k + 2; i++)
    {
        s = (nfac * qpow(n - i, mod - 2)) % mod;
        s = (s * qpow(fac[i - 1], mod - 2)) % mod;
        s = (s * qpow(fac[k + 2 - i], mod - 2)) % mod;
        s = s * qpow(-1, k + 2 - i);
        s = (s * a[i]) % mod;
        ans = (ans + s + mod) % mod;
    }
    printf("%I64d\n", ans);
    return 0;
}