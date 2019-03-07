#include <bits/stdc++.h>
using namespace std;
#define rep(i, st, en) for (i = st; i <= en; i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
int f[505][505][2];
char st[505];
char a[505];
int main()
{
    int n, m, i, j, k, s, t;
    scanf("%d", &m);
    scanf("%s", st);
    n = 1;
    a[0] = st[0];
    for (i = 1; i < m; i++)
        if (st[i] != st[i - 1])
            a[n++] = st[i];
    memset(f, 0, sizeof(f));
    //printf("%s\n", a);
    for (k = 2; k <= n; ++k) {
        for (i = 0; i + k - 1 <= n - 1; ++i) {
            if (a[i] == a[i + k - 1]) {
                f[i][i + k - 1][0] = f[i][i + k - 1][1] = min(f[i + 1][i + k - 2][0], f[i + 1][i + k - 2][1]) + 1;
            } else {
                f[i][i + k - 1][0] = f[i][i + k - 1][1] = n;
            }
            for (j = i; j <= i + k - 2; ++j) {
                s = min(f[i][j][0] + 1, f[i][j][1] + 1);
                t = min(f[j + 1][i + k - 1][0] + 1, f[j + 1][i + k - 1][1] + 1);
                if (a[i] == a[i + k - 1])
                    f[i][i + k - 1][0] = min(f[i][i + k - 1][0], min(s, f[i][j][0]) + min(t, f[j + 1][i + k - 1][1]));
                else
                    f[i][i + k - 1][0] = min(f[i][i + k - 1][0], min(s, f[i][j][0]) + t);
                if (a[i] == a[i + k - 1])
                    f[i][i + k - 1][1] = min(f[i][i + k - 1][1], min(s, f[i][j][0]) + min(t, f[j + 1][i + k - 1][1]));
                else
                    f[i][i + k - 1][1] = min(f[i][i + k - 1][1], s + min(t, f[j + 1][i + k - 1][1]));
            }
            //printf("%d %d: %d %d\n", i, i + k - 1, f[i][i + k - 1][0], f[i][i + k - 1][1]);
        }
    }
    printf("%d\n", min(f[0][n - 1][0], f[0][n - 1][1]) + 1);
    return 0;
}