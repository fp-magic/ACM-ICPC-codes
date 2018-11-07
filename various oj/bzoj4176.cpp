#include <cstdio>
#include <map>
#define ll long long
using namespace std;
/*
神奇的利用莫比乌斯反演的一个结论得到了公式，之后结合杜教筛就可以了。
*/
const ll mod = 1e9 + 7;
map<ll, ll> f;
map<ll, ll>::iterator it;
ll m = 1600000, miu[1600005], prime[1600005], sum[1600005], tot;
bool np[1600005];
void Get_miu()
{
    ll i, j;
    miu[1] = sum[1] = 1;
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
        sum[i] = sum[i - 1] + miu[i];
    }
}
ll query(ll n)
{
    if (n <= m)
        return sum[n];
    it = f.find(n);
    if (it != f.end())
        return it->second;
    ll ans = 1, i, last;
    for (i = 2; i <= n; i = last + 1)
        last = n / (n / i), ans -= (last - i + 1) * query(n / i);
    f.insert(make_pair(n, ans));
    return ans;
}
ll cal(ll n)
{
    ll i, last = 0, ans = 0;
    for (i = 1; i <= n; i = last + 1)
    {
        last = n / (n / i);
        ans = (ans + (n / i) * (last - i + 1)) % mod;
    }
    return (ans * ans) % mod;
}
int main()
{
    ll n, m, i, j, k, s, t, ans = 0, last = 0;
    Get_miu();
    scanf("%lld", &n);
    for (i = 1; i <= n; i = last + 1)
    {
        last = n / (n / i);
        ans = (ans + (mod + query(last) - query(i - 1)) % mod * cal(n / i)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}