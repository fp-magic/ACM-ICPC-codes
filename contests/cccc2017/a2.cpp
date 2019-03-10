#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<cmath>
using namespace std;
vector<int> a[100005];
double b[100005];
double v;
double dfs(int x, double u)
{
    double sum=0;
    if (a[x].size() == 0)
    {//printf("%d %f %f %f\n",x,u,b[x],u*b[x]);
        return u * b[x];
    }
    for (int i = 0; i < a[x].size(); i++) {
        sum += dfs(a[x][i], u * v);
    }
    return sum;
}
int main()
{
    int n, m, i, j, k, s, t;
    double u;
    scanf("%d%lf%lf", &n, &u, &v);
    v=1.00-0.01*v;
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        for (j = 1; j <= m; j++) {
            scanf("%d", &k);
            a[i].push_back(k);
        }
        if (m == 0)
            scanf("%lf", &b[i]);
    }
    printf("%.0f\n", floor(dfs(0, u)));
    return 0;
}