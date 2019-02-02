#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
long long f[100005][205];
struct node {
    int s, t, d;
    long long w;
} a[100005];
int main()
{
    int n, m, x, y, d, i, j, k, s, t, tt;
    scanf("%d%d%d", &n, &m, &k);
    memset(f, 0, sizeof(f));
    for (i = 1; i <= k; i++)
        scanf("%d%d%d%I64d", &a[i].s, &a[i].t, &a[i].d, &a[i].w);
    for (i = 1; i <= n; i++) {
    }
    return 0;
}