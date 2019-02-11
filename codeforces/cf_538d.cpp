#include <bits/stdc++.h>
using namespace std;
#define rep(i, st, en) for (i = st; i <= en; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
ll fmod(ll b, ll exp)
{
    ll res = 1;
    while (exp) {
        if (exp & 1ll)
            res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2ll;
    }
    return res;
}
int a[5005],b[5005];
int f[5005][5005];
int main()
{
    int n, m, i, j, k, s, t;
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    n=1;
    a[1]=b[1];
    for(i=2;i<=m;i++)
    if(b[i]!=b[i-1])a[++n]=b[i];
    memset(f, 127, sizeof(f));
    for (i = 1; i <= n; i++)
        f[i][i] = 0;
    for (k = 2; k <= n; k++)
        for (i = 1; i <= n - k + 1; i++) {
            j = i + k - 1;
            if (a[i] == a[j]) {
                if (k == 2)
                    f[i][j] = 0;
                else
                    f[i][j] = f[i + 1][j - 1] + 1;
            } else {
                f[i][j]=min(f[i][j-1],f[i+1][j])+1;
            }
        }
    printf("%d\n",f[1][n]);
    return 0;
}