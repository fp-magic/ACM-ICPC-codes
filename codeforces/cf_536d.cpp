#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[100005];
vector<int> ans;
int flag[100005], n;
priority_queue<int> q;
int main()
{
    int m, x, y, d, i, j, k, s, t, tt;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        a[i].clear();
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &s, &t);
        a[s].push_back(t);
        a[t].push_back(s);
    }
    memset(flag, 0, sizeof(flag));
    while (!q.empty())
        q.pop();
    q.push(-1);
    flag[1] = 1;
    for (j = 1; j <= n; j++) {
        t = -q.top();
        q.pop();
        printf("%d ", t);
        for (i = 0; i < a[t].size(); i++)
            if (!flag[a[t][i]]) {
                q.push(-a[t][i]);
                flag[a[t][i]] = 1;
            }
    }
    return 0;
}