#include <bits/stdc++.h>
#define mn 200005
using namespace std;
int n, k, p[mn], t[mn];
struct Node
{
    int x, y, t, i;
} a[mn];
bool cmp1(Node x, Node y)
{
    if (x.x != y.x)
        return x.x < y.x;
    return x.y < y.y;
}
bool cmp2(Node x, Node y)
{
    if (x.y != y.y)
        return x.y < y.y;
    return x.x < y.x;
}
int find(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}
bool check(int x)
{
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(i) != i)
            continue;
        if (t[i] > x)
            ++tot;
    }
    return tot <= x + 1;
}
void work()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].t);
        a[i].i = i;
        p[i] = i;
        t[i] = a[i].t;
    }
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].x != a[i - 1].x)
            continue;
        if (a[i].y - a[i - 1].y > k)
            continue;
        int fx = find(a[i].i), fy = find(a[i - 1].i);
        if (fx == fy)
            continue;
        t[fx] = min(t[fx], t[fy]);
        p[fy] = fx;
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].y != a[i - 1].y)
            continue;
        if (a[i].x - a[i - 1].x > k)
            continue;
        int fx = find(a[i].i), fy = find(a[i - 1].i);
        if (fx == fy)
            continue;
        t[fx] = min(t[fx], t[fy]);
        p[fy] = fx;
    }
    int l = 0, r = n;
    while (l <= r)
    {
        int mid = ((l + r) >> 1);
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}
signed main()
{
    int T = 1;
    scanf("%d\n", &T);
    while (T--)
        work();
    return 0;
}