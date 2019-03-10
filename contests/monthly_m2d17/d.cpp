#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200000;
const long long p = 100000007700000049ll, mod[2] = {1000000007ll,100000007ll };

long long f[maxn + 10];
long long ksc(long long a, long long b)
{
    long long ans = 0ll;
    while (b) {
        if (b & 1ll) {
            b--;
            ans = (ans + a) % p;
        }
        b /= 2ll;
        a = (a + a) % p;
    }
    return ans;
}
void init()
{
    f[0] = 1ll;
    for (long long i = 1; i <= maxn; i++) {
        f[i] = (long long)ksc(f[i - 1], i);
    }
}

long long fast(long long a, long long n)
{
    if (n == 0ll)
        return 1ll;
    if (n % 2ll)
        return ksc(a, fast(a, n - 1ll));
    long long tmp = fast(a, n / 2ll);
    return ksc(tmp, tmp);
}

long long C(long long n, long long m)
{
    if (n == m || m == 0ll)
        return 1ll;
    return ksc(ksc(f[n], fast(f[m], p - 2ll)), fast(f[n - m], p - 2ll));
}

void China(int n,int m)
{
    long long ans = 0, Mod,odd[2];
    for (int i = 0; i < 2; i++) {
        Mod = mod[i];
        odd[i] = C(n, m) % Mod;
        ans = ans + ksc(ksc(p / mod[i], fast(p / mod[i], mod[i] - 2)), odd[i]);
    }
    printf("%lld\n", (ans + p) % p);
}
int main()
{
    init();
    long long n, m;
    while (~scanf("%lld%lld", &n, &m)) {
        China(n,m);
    }
    return 0;
}