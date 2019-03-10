#include <bits/stdc++.h>
using namespace std;
#define rep(i, st, en) for (i = st; i <= en; i++)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
struct node {
    ll num;
    double sum;
    double w;
    node(){}
    node(ll nm, double sm, double pw)
    {
        num = nm;
        sum = sm;
        w = pw;
    }
    bool operator<(const node& r) const
    {
        return w > r.w;
    }
};
ll c[25][25];
double f[4];
priority_queue<node> q;
void dfs(ll step, ll res, double prob, ll num)
{
    double now = 1;
    if (step == 4) {
        if (res == 0)
            q.push(node(num, prob * (double)num, prob));
        return;
    }
    for (ll i = 0; i <= res; i++) {
        dfs(step + 1, res - i, prob * now, num * c[res][i]);
        now *= f[step];
        //printf("%.5f %.5f\n",now,f[step]);
    }
}

int main()
{
    ll n, m, i, j, k, root;
    double ans;
    node s, t;
    scanf("%I64d", &n);
    scanf("%lf%lf%lf%lf", &f[0], &f[1], &f[2], &f[3]);
    for (i = 0; i <= 20; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (j = 1; j < i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    dfs(0, n, 1, 1);
    ans = 0;
    //printf("%d\n",q.size());
    while (q.size() > 1) {
        s = q.top();
        //printf("%I64d %.10f %.10f\n",s.num,s.sum,s.w);
        q.pop();
        if(s.sum<1e-16)continue;
        if (s.num > 1) {
            if (s.num & 1) {
                q.push(node(s.num / 2, s.sum - s.w, s.w * 2.0));
                ans += s.sum - s.w;
                q.push(node(1, s.w, s.w));
            } else {
                q.push(node(s.num / 2, s.sum, s.w * 2.0));
                ans += s.sum;
            }
        } else {
            t = q.top();
            //printf("=%I64d %.10f %.10f\n",t.num,t.sum,t.w);
            q.pop();
            q.push(node(1, s.sum + t.w, s.w + t.w));
            ans += s.sum + t.w;
            if (t.num > 1)
                q.push(node(t.num - 1, t.sum - t.w, t.w));
        }
        //printf("%.10f\n",ans);
    }
    printf("%.6f\n", ans);
    return 0;
}