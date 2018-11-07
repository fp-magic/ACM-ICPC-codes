#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define maxn 50010
using namespace std;
/*
莫比乌斯反演&&分块练习题，从某个博客中学习到了巧妙的分块写法
*/
ll g[maxn], miu[maxn], cnt, prime[maxn], vis[maxn];
void Get_miu()
{
    ll i, j, last;
    for (i = 1; i < maxn; i++)
    {
        for (int j = 1; j <= i; j = last + 1)
        {
            last = i / (i / j);
            g[i] += (i / j) * (last - j + 1);
        }
    }
    vis[1] = 1;
    miu[1] = 1;
    for (i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[++cnt] = i;
            miu[i] = -1;
        }
        for (j = 1; j <= cnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                miu[i * prime[j]] = 0;
                break;
            }
            else
                miu[i * prime[j]] = -miu[i];
        }
    }
    for (int i = 1; i < maxn; i++)
        miu[i] += miu[i - 1];
}
int main()
{
    ll n, m, i, j, k, s, t, tt, ans;
    Get_miu();
    scanf("%lld", &tt);
    while (tt--)
    {
        scanf("%lld%lld", &n, &m);
        ans = 0;
        int last;
        for (i = 1; i <= min(n,m); i = last + 1)
        {
            last = min(n / (n / i), m / (m / i));
            ans += (miu[last] - miu[i - 1]) * g[n / i] * g[m / i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}