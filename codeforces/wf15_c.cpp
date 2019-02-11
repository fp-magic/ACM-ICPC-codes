#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll M = 205;
const ll inf = (ll)1e15;
ll n, nx, ny;
ll link[M], lx[M], ly[M], slack[M];
ll visx[M], visy[M], w[M][M];

ll DFS(ll x)
{
    visx[x] = 1;
    for (ll y = 1; y <= ny; y++) {
        if (visy[y])
            continue;
        ll t = lx[x] + ly[y] - w[x][y];
        if (t == 0) //
        {
            visy[y] = 1;
            if (link[y] == -1 || DFS(link[y])) {
                link[y] = x;
                return 1;
            }
        } else if (slack[y] > t)
            slack[y] = t;
    }
    return 0;
}
ll KM()
{
    ll i, j;
    memset(link, -1, sizeof(link));
    memset(ly, 0, sizeof(ly));
    for (i = 1; i <= nx; i++)
        for (j = 1, lx[i] = -inf; j <= ny; j++)
            if (w[i][j] > lx[i])
                lx[i] = w[i][j];

    for (ll x = 1; x <= nx; x++) {
        for (i = 1; i <= ny; i++)
            slack[i] = inf;
        while (1) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if (DFS(x))
                break;
            ll d = inf;
            for (i = 1; i <= ny; i++)
                if (!visy[i] && d > slack[i])
                    d = slack[i];
            for (i = 1; i <= nx; i++)
                if (visx[i])
                    lx[i] -= d;
            for (i = 1; i <= ny; i++)
                if (visy[i])
                    ly[i] += d;
                else
                    slack[i] -= d;
        }
    }
    ll res = 0;
    for (i = 1; i <= ny; i++)
        if (link[i] > -1)
            res += w[link[i]][i];
    return res;
}
int main()
{
    ll i, j, k, s, t;
    scanf("%I64d%I64d", &n, &k);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + k; j++)
            w[i][j] =-inf;
    for (j = 1; j <= n; j++) {
        scanf("%I64d", &s);
        for (i = n + 1; i <= n + k; i++)
            w[j][i] = -s;
    }
    for (i = 1; i <= n - 1; i++)
        for (j = 1; j <= n - i; j++) {
            scanf("%I64d", &s);
            w[i + j][i] = -s;
        }
    nx = n;
    ny = n + k;
    /*for (i = 1; i <= nx; i++) {
        for (j = 1; j <= ny; j++)
            printf("%I64d ", w[i][j]);
        printf("\n");
    }*/
    printf("%I64d\n", -KM());
    return 0;
}