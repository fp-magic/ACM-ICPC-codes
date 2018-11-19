#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
vector<int> a[2505];
long long f[2505];
long long ans[2505];
//node i is colored with some certain color, with every son-node already colored.
int n, k;
long long qpow(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}
void dfs(int x)
{
    int i, j;
    long long s = 1;
    for (i = 0; i < a[x].size(); i++)
    {
        dfs(a[x][i]);
        s = (s * f[a[x][i]] % mod * (long long)(k - 1)) % mod;
    }
    f[x] = s;
    return;
}
int main()
{
    int i, j, t;
    long long s, p;
    scanf("%d%d", &n, &k);
    for (i = 0; i <= n - 1; i++)
        a[i].clear();
    for (i = 1; i <= n - 1; i++)
    {
        scanf("%d", &t);
        a[t].push_back(i);
    }
    s = 0;
    i = k;
    p = k;
    while (k > 0)
    {
        memset(f, 0, sizeof(f));
        dfs(0);
        if (!((i - k) & 1))
            s = (s + (f[0] * p)) % mod;
        else
            s = (s - ((f[0] * p) % mod) + mod) % mod;
        //printf("%d: %I64d\n", k, f[0]*p);
        k--;
        p = p * k % mod;
        p = p * qpow(i - k, mod - 2) % mod;
    }
    printf("%I64d\n", s);
    return 0;
}