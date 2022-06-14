#include <bits/stdc++.h>
using namespace std;
long long a[505][505];
long long f[505][505];
int main()
{
    int n, m, i, j, k, tt;
    long long ans, s, t;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d", &n);
        for (i = 0; i < n * 2; ++i)
        {
            for (j = 0; j < n * 2; ++j)
            {
                scanf("%lld", &a[i][j]);
            }
        }
        ans = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                ans += a[i][j] + a[i + n][j + n];
            }
        }
        s = min(min(a[n - 1][n], a[n][n - 1]), min(a[n - 1][n * 2 - 1], a[n][0]));
        s = min(s, min(a[2 * n - 1][n - 1], a[0][n]));
        s = min(s, min(a[0][2 * n - 1], a[2 * n - 1][0]));
        printf("%lld\n", ans + s);
    }
    return 0;
}