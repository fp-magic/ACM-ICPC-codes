#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 5;
const int maxm = 1e5 + 5;
int g[maxn];
int a[maxm];
long long vit[maxn];
long long dfs(int now, int precnt)
{
    //printf("%d %d %lld\n", now, precnt, vit[now]);
    if (vit[now] != -1)
    {
        return (long long)vit[now] + ((long long)(g[now] - precnt)) * now;
    }
    long long sum = 0;
    for (int i = 1; i <= sqrt(now); ++i)
        if (now % i == 0)
        {
            if (i < now)
                sum = max(sum, dfs(i, g[now]));
            if (i > 1)
                sum = max(sum, dfs(now / i, g[now]));
        }
    vit[now] = sum;
    //printf("===%d %d %d %d %lld\n", now, precnt, vit[now], g[now], (long long)(g[now] - precnt) * now + sum);
    return (long long)(g[now] - precnt) * now + sum;
}
int main()
{
    int n, m, i, j, k, t, tt;
    long long ans, s;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    memset(g, 0, sizeof(g));
    for (i = 0; i < n; ++i)
    {
        for (j = 1; j <= sqrt(a[i]); ++j)
        {
            if (a[i] % j == 0)
            {
                g[j]++;
                if (a[i] != j * j)
                {
                    g[a[i] / j]++;
                }
            }
        }
    }
    memset(vit, 255, sizeof(vit));
    ans = n;
    vit[1] = 0;
    for (i = n - 1; i >= 0; --i)
        if (vit[a[i]] == -1)
        {
            //printf("?%d\n", a[i]);
            ans = max(ans, dfs(a[i], 0));
        }
    printf("%lld\n", ans);
    return 0;
}