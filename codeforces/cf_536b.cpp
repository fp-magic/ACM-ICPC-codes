#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct node {
    int x, idx;
} b[100005];
int cmp(node l, node r) { return l.x < r.x || (l.x == r.x && l.idx < r.idx); }

long long a[100005], c[100005], t, d;
int main()
{
    long long n, m, x, y, i, j, k, s, tt, now;
    scanf("%I64d%I64d", &n, &m);
    s = 0;
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        s += a[i];
    }
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &c[i]);
        b[i].idx = i;
        b[i].x = c[i];
    }
    sort(b + 1, b + n + 1, cmp);
    now = 0;
    for (i = 1; i <= m; i++) {
        // for (int ti = 1; ti <= n; ti++)
        //    printf("==%I64d %I64d\n", a[ti], c[ti]);
        scanf("%I64d%I64d", &t, &d);
        if (s < d) {
            printf("0\n");
            s = 0;
        } else {
            s -= d;
            if (a[t] >= d) {
                a[t] -= d;
                printf("%I64d\n", d * c[t]);
            } else {
                k = a[t] * c[t];
                d -= a[t];
                a[t] = 0;
                while (d > 0) {
                    // printf("%I64d %I64d %I64d\n", d, a[b[now].idx], c[b[now].idx]);
                    if (a[b[now].idx] >= d) {
                        k += d * c[b[now].idx];
                        a[b[now].idx] -= d;
                        d = 0;
                    } else {
                        k += c[b[now].idx] * a[b[now].idx];
                        d -= a[b[now].idx];
                        a[b[now].idx] = 0;
                        now++;
                    }
                }
                printf("%I64d\n", k);
            }
        }
    }
    return 0;
}