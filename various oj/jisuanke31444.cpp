#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
/*
杰霸出的沈阳网络赛的题目，参照网上的博客学会了一种快速乘法和取模的技巧
*/
ll m = 340000, miu[340005], prime[340005], tot, p;
bool np[340005];
void Get_miu()
{
    ll i, j;
    miu[1] = 1;
    for (i = 2; i <= m; i++)
    {
        if (!np[i])
            miu[i] = -1, prime[++tot] = i;
        for (j = 1; j <= tot && i * prime[j] <= m; j++)
        {
            np[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                miu[i * prime[j]] = 0;
                break;
            }
            else
                miu[i * prime[j]] = -miu[i];
        }
    }
}
const ll lb = (1LL << 20) - 1;
ll fast_c(ll x, ll y, ll md)
{
    ll a = x >> 20, b = x & lb;
    ll c = y >> 20, d = y & lb;
    return ((((((a * c) << 20) + (a * d + b * c)) % md) << 20) + b * d) % md;
}
ll getsum2(ll x)
{
    return fast_c(fast_c(x, x + 1, 6 * p), (2 * x + 1), 6 * p) / 6 % p;
}
ll getsum3(ll x)
{
    ll tp = fast_c(x, x + 1, p << 1) >> 1;
    return fast_c(tp, tp, p);
}
int main()
{
    ll n, i, j, k, s, t, ans;
    Get_miu();
    while (scanf("%lld%lld", &n, &p) != EOF)
    {
        ans = 0;
        for (i = 1; i * i <= n; i++)
        {
            t = i * i, s = fast_c(t, t, p);
            ans = (ans + miu[i] * fast_c(fast_c(s, n + 1, p), getsum2(n / t), p)) % p;
            ans = (ans - miu[i] * fast_c(fast_c(s, t, p), getsum3(n / t), p)) % p;
            
        }
        printf("%lld\n", (ans + p + p) % p);
    }
    return 0;
}