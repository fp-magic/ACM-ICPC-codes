#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int a[300005];
int main()
{
    int n, m, x, y, d, i, j, k, tt;
    long long s, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    s = 0;
    for (i = 1; i <= n / 2; i++)
        s += (long long)((a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]));
    printf("%I64d\n", s);
    return 0;
}