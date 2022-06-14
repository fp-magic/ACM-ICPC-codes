#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n, m, i, j, k, s, t, p, q, tt, ans;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d", &n);
        m = 0;
        s = 0;
        t = 0;
        p = 0;
        q = 0;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &k);
            a[i] = k;
            m = max(k, m);
            if (k == 1)
                s = 1, t = 1;
            if (k % 3 == 1)
                s = 1;
            if (k % 3 == 2)
                p = 1;
        }
        for (i = 0; i < n; ++i)
            if (a[i] == m - 1)
                q = 1;
        if (m % 3 == 0)
        {
            if (s == 1 || p == 1)
                ans = m / 3 + 1;
            else
                ans = m / 3;
        }
        else if (m % 3 == 1)
        {
            if ((t == 1 || q == 1) & p == 1)
                ans = m / 3 + 2;
            else
                ans = m / 3 + 1;
        }
        else
        {
            if (s == 1)
                ans = m / 3 + 2;
            else
                ans = m / 3 + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}