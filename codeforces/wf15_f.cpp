#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct node {
    node()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    node(int px, int py)
    {
        x = px;
        y = py;
        z = -1;
    }
    node(int px, int py, int pz)
    {
        x = px;
        y = py;
        z = pz;
    }
    int x, y, z;
};
char bd[55][55];
int dis[55][55][10005];
node nxt[55][55][4];
int r, c, len;
char a[10005];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
queue<node> q;
void init()
{
    int i, j, k, x, y;
    scanf("%d%d", &r, &c);
    for (i = 0; i < r; i++) {
        getchar();
        scanf("%s", bd[i]);
    }
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            for (k = 0; k < 4; k++) {
                x = i;
                y = j;
                while (bd[x][y] == bd[i][j] && (x + dx[k]) >= 0 && (x + dx[k]) < r && (y + dy[k]) >= 0 && (y + dy[k]) < c) {
                    x += dx[k];
                    y += dy[k];
                }
                if (bd[x][y] == bd[i][j])
                    nxt[i][j][k] = node(i, j);
                else
                    nxt[i][j][k] = node(x, y);
                //printf("%d %d %d: %d %d\n", i, j, k, x, y);
            }
        }
    scanf("%s", a);
    len = strlen(a);
    a[len++] = '*';
}
void solve()
{
    int i, j, k, px, py, pz, nx, ny, nz;
    memset(dis, 255, sizeof(dis));
    while (!q.empty())
        q.pop();
    q.push(node(0, 0, 0));
    dis[0][0][0] = 0;
    while (!q.empty()) {
        px = q.front().x;
        py = q.front().y;
        pz = q.front().z;
        q.pop();
        if (pz >= len)
            continue;
        for (k = 0; k < 4; k++) {
            nx = nxt[px][py][k].x;
            ny = nxt[px][py][k].y;
            nz = pz;
            if (dis[nx][ny][nz] == -1) {
                dis[nx][ny][nz] = dis[px][py][pz] + 1;
                q.push(node(nx, ny, nz));
            }
        }
        if (bd[px][py] == a[pz])
            if (dis[px][py][pz + 1] == -1) {
                dis[px][py][pz + 1] = dis[px][py][pz] + 1;
                q.push(node(px, py, pz + 1));
            }
    }
    k = r * c * len;
    /*for (k = 0; k <= len; k++)
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                printf("%d %d %d: %d\n", i, j, k, dis[i][j][k]);*/
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (dis[i][j][len] != -1)
                k = min(k, dis[i][j][len]);
    printf("%d\n", k);
}
int main()
{
    init();
    solve();
    return 0;
}