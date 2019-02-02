#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char a[505][505];
int main()
{
    int n, m, x, y, d, i, j, k, s, t, tt;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        getchar();
        scanf("%s", a[i]);
    }
    s = 0;
    for (i = 1; i < n - 1; i++)
        for (j = 1; j < n - 1; j++)
            if (a[i][j] == 'X' && a[i - 1][j - 1] == 'X' && a[i - 1][j + 1] == 'X' && a[i + 1][j - 1] == 'X' && a[i + 1][j + 1] == 'X')
                s++;
    printf("%d\n", s);
    return 0;
}