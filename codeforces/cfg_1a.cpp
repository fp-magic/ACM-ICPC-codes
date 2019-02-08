#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    int b, n, m, i, j, k, s, t;
    scanf("%d%d", &b, &k);
    s = 0;
    for (i = k - 1; i >= 0; i--) {
        scanf("%d", &t);
        if (t != 0) {
            if (i != 0)
                s += (b * t) % 2;
            else
                s += t % 2;
        }
    }
    if (s % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
    return 0;
}