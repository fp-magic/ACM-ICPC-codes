#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 900005
#define maxm 900005
const long long mod = 1e9 + 7;
struct node
{
    int v, next;
} edge[maxm];
int cnt, head[maxn];
int deep[maxn];
struct Q
{
    int u, v;
    int lca;
    int next;
    int flag;
} qu[maxm];
int cnt2, head2[maxn];
int p[maxn], fa[maxn];
bool vis[maxn];
int n, m, k;
int line[maxm];
int pass[maxn], bg[maxn];
long long ans, C[maxn];
#define find Find
int find(int x)
{
    return p[x] == x ? p[x] : p[x] = find(p[x]);
}
void add_edge(int u, int v)
{
    edge[cnt].v = v, edge[cnt].next = head[u], head[u] = cnt++;
}
void add_query(int u, int v) { qu[cnt2].u = u, qu[cnt2].v = v, qu[cnt2].next = head2[u], head2[u] = cnt2++; }
long long pow_mod(long long x, long long n) //x^n%c
{
    if (n == 1)
        return x % mod;
    x %= mod;
    long long tmp = x;
    long long ret = 1;
    while (n)
    {
        if (n & 1)
            ret = ret * tmp % mod;
        tmp = tmp * tmp % mod;
        n >>= 1;
    }
    return ret;
}
void preC()
{
    long long i;
    for (i = 0; i < k; i++)
        C[i] = 0;
    C[k] = 1;
    for (i = k + 1; i <= m; i++)
    {
        C[i] = C[i - 1] * i % mod * pow_mod(i - k, mod - 2) % mod;
    }
}
void LCA(int u, int father, int d)
{ //printf("%d\n",u);
    vector<int> tocnt;
    tocnt.clear();
    deep[u] = d;
    p[u] = u;
    fa[u] = father;
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    { //printf("=%d\n",i);
        int v = edge[i].v;
        if (vis[v])
            continue;
        LCA(v, u, d + 1);
        p[v] = u;
        tocnt.push_back(v);
    }
    for (int i = 0; i < tocnt.size(); i++)
    {
        pass[u] += pass[tocnt[i]] - bg[tocnt[i]];
    }
    int tmp = 0;
    //printf("!%d\n",u);
    for (int i = head2[u]; i != -1; i = qu[i].next)
    { //printf("+%d\n",i);
        int v = qu[i].v;
        if (vis[v])
        {
            if (qu[i].lca ==-1)
            { //printf("-%d %d %d %d %d %d\n",u,v,find(v),pass[u],pass[v],pass[find(v)]);
                pass[find(v)]--;
                if(qu[i].flag==0)
                {
                    pass[u]++;
                    pass[v]++;
                    qu[i^1].flag=qu[i].flag=1;
                }
                //printf("=%d %d %d %d %d %d\n",u,v,find(v),pass[u],pass[v],pass[find(v)]);
            }
            qu[i ^ 1].lca = qu[i].lca = find(v);
            if (u != find(v))
                bg[find(v)]++;
            if (u == v)
                tmp++;
            //printf("%d %d %d\n",u,v,find(v));
        }else
        {
            pass[u]++;
            pass[v]++;
            qu[i^1].flag=qu[i].flag=1;
        }
    }
    bg[u] += tmp / 2;
    //for(int i=1;i<=n;i++)printf("!%d: %d %d\n",i,pass[i],bg[i]);
}
int main()
{
    int tt, i, j, s, t;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (i = 0; i <= n; i++)
            fa[i] = i;
        for (i = 0; i <= 2 * m; i++)
            qu[i].lca = -1, qu[i].flag=0,C[i] = 0, head[i] = -1, head2[i] = -1;
        for (i = 0; i <= n; i++)
            pass[i] = 0, bg[i] = 0, vis[i] = 0;
        preC();
        cnt = 0;
        cnt2 = 0;
        ans = 0;
        for (i = 1; i <= n - 1; i++)
        {
            scanf("%d%d", &s, &t);
            add_edge(s, t);
            add_edge(t, s);
        }
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &s, &t);
            add_query(s, t);
            add_query(t, s);
        }
        LCA(1, 1, 0);
        //for(i=1;i<=n;i++)
        //printf("%d: %d %d %d %I64d %I64d\n",i,pass[i],bg[i],pass[i]-bg[i],C[pass[i]],C[pass[i]-bg[i]]);
        for (i = 1; i <= n; i++)
        if(pass[i]<bg[i])break;
        else ans = (ans + C[pass[i]] - C[pass[i] - bg[i]] + mod + mod) % mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
/*
10
7 30 3
1 2
2 3
2 4
2 5
2 6
6 7
1 1
1 2
1 3
1 4
1 5
1 6
1 7
2 2
2 3
2 4
2 5
2 6
2 7
3 3
3 4
3 5
3 6
3 7
4 4
4 5
4 6
4 7
5 5
5 6
5 7
6 6
6 7
7 7
3 5
4 6
7 9 3
1 2
2 3
2 4
2 5
2 6
6 7
1 1
1 2
1 3
1 4
1 5
1 6
1 7
2 2
2 3
*/