#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int a[25][25];
vector<int> b[25];
int out[25];
queue<int> q;
stack<int> st;
int n, now;
vector<int> ans;
int vis[25];
int dis[25][25];
bool dfs(int x)
{

    if (st.size() == n - 1) {
        if (a[x][now]) {
            st.push(x);
            return true;
        } else
            return false;
    }
    if(dis[x][now]>n+1-st.size())return false;
    st.push(x);
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); ++i)
        if (!vis[b[x][i]]) {
            if (dfs(b[x][i]))
                return true;
        }
    vis[x] = 0;
    st.pop();
    return false;
}
int main()
{
    int m, i, j, k, s, t;
    char ch;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++) {
        getchar();
        b[i].clear();
        for (j = 1; j <= n; j++) {
            scanf("%c", &ch);
            if (ch == 'W') {
                if (!a[i][j])
                    a[i][j] = 1, out[i]++;
            } else if (ch == 'L')
                if (!a[j][i]) {
                    a[j][i] = 1, out[j]++;
                }
        }
    }
    for (i = 1; i <= n; i++)
        if (out[i] == 0)
            q.push(i);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        for (i = 1; i <= n; i++)
            if (a[i][s]) {
                a[i][s] = 0;
                out[i]--;
                if (out[i] == 0)
                    q.push(i);
            }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j])
                b[i].push_back(j);
    }

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(a[i][j])dis[i][j]=1;else dis[i][j]=9999;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=n;k++)
    if(i!=j&&i!=k&&j!=k)
    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);

    for (now = 1; now <= n; now++) {
        memset(vis, 0, sizeof(vis));
        while (!st.empty())
            st.pop();
        if (dfs(now))
            break;
    }
    
    if (st.size() != n)
        printf("No Solution");
    else {
        ans.clear();
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        for(i=ans.size()-1;i>=1;i--)printf("%d ",ans[i]);
        printf("%d\n",ans[0]);
    }
}//2412 1926 1728