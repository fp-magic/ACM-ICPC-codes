#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/*
暴力枚举集合点，每次在两边找一个最远的能安全抵达集合点的骑士过去
*/
int a[105], h[105], vit[105], num[105];
vector<int> ans;
int main()
{
    int rap, n, m, i, j, k, s, t, ddl, midnum, flag;
    scanf("%d%d", &n, &m);
    memset(h, 0, sizeof(h));
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &s, &t);
        h[s] = t;
        num[s] = i;
    }
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    midnum = 0;
    for (rap = 1; rap <= n; rap++)
    {
        ans.clear();
        flag = 1;
        memset(vit, 0, sizeof(vit));
        while (flag && ans.size() < m)
        {
            s = 0;
            ddl = 0;
            k = 105;
            flag = 0;
            for (i = rap; i >= 1; i--)
                if (h[i] > 0 && !vit[i])
                {
                    if (h[i] > 0 && h[i] >= -s - ddl && !vit[i])
                    {
                        flag = 1;
                        k = min(k, i);
                    }
                }
                else if (!vit[i])
                {
                    s += a[i];
                    ddl = min(ddl, -s);
                }
            if (flag)
            {
                ans.push_back(k);
                for (i = k; i <= rap; i++)
                    if (h[i] == 0)
                        vit[i] = 1;
                vit[k] = 1;
                continue;
            }
            s = 0;
            ddl = 0;
            k = 0;
            for (i = rap; i <= n; i++)
            {
                if (h[i] > 0 && h[i] >= -s - ddl && !vit[i])
                {
                    flag = 1;
                    k = max(k, i);
                }
                else if (!vit[i])
                {
                    s += a[i];
                    ddl = min(ddl, -s);
                }
            }
            if (flag)
            {
                ans.push_back(k);
                for (i = rap; i <= k; i++)
                    if (h[i] == 0)
                        vit[i] = 1;
                vit[k] = 1;
                continue;
            }
        }
        if (ans.size() == m)
            break;
    }
    if (ans.size() == m)
    {
        printf("%d\n", rap);
        for (i = 0; i < m; i++)
            printf("%d ", num[ans[i]]);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}