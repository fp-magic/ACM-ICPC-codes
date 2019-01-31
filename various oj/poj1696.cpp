#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-7;
struct node
{
    int idx;
    double x, y;
    void output()
    {
        printf("%.2lf %.2lf\n",x,y);
    }
} a[55];
int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return (x < 0 ? -1 : 1);
}
double det(node pre, node now, node now2, node nxt)
{
    double lx, ly, rx, ry;
    lx = now.x - pre.x;
    ly = now.y - pre.y;
    rx = nxt.x - now2.x;
    ry = nxt.y - now2.y;
    return lx * ry - ly * rx;
}
double dis(node now, node nxt)
{
    double lx, ly;
    lx = (nxt.x - now.x) * (nxt.x - now.x);
    ly = (nxt.y - now.y) * (nxt.y - now.y);
    return sqrt(lx + ly);
}
vector<int> ans;
int vit[55];
int main()
{
    int tt, n, m, i, j, k, now, nxt, pre;
    double s, t, l, r;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%d%lf%lf", &k, &s, &t);
            a[k].idx = k;
            a[k].x = s;
            a[k].y = t;
        }
        memset(vit, 0, sizeof(vit));
        ans.clear();
        now = 1;
        for (i = 1; i <= n; i++)
            if (a[i].y < a[now].y)
                now = i;
        pre = 0;
        a[0].x = 0;
        a[0].y = a[now].y;
        ans.push_back(now);
        vit[now] = 1;
        do
        {
            //a[pre].output();
            //a[now].output();
            nxt = -1;
            for (i = 1; i <= n; i++)
                if (!vit[i] && det(a[now], a[i], a[now], a[pre]) > 0)
                {
                    //printf("%d: %.2f\n",i,det(a[now], a[i], a[now], a[pre]));
                    if (nxt == -1 || det(a[now], a[nxt], a[now], a[i]) < 0 || (dcmp(det(a[now], a[nxt], a[now], a[i])) == 0 && dis(a[now], a[i]) < dis(a[now], a[nxt])))
                        nxt = i;
                }
            if (nxt == -1)
                break;
            ans.push_back(nxt);
            vit[nxt] = 1;
            pre=now;
            now=nxt;
        }while(nxt!=-1);
        printf("%d", ans.size());
        for (i = 0; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}