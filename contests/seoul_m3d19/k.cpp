#include <algorithm>
#include <cstdio>
#include <cstring>
#include<queue>
#include <vector>
using namespace std;
int dfn[10005], low[10005], vis[10005], clr[10005], stk[10005], dfs_num, col_num, top;
vector<int> a[10005],scc[10005],ra[10005];
queue<int>q;
int use[10005];
void Tarjan_init()
{
    col_num = 0;
    dfs_num = 0;
    top = 0;
    memset(clr, 0, sizeof(clr));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(vis, 0, sizeof(vis));
    memset(stk, 0, sizeof(stk));
}
void Tarjan(int x)
{
    dfn[x] = ++dfs_num;
    low[x] = dfs_num;
    vis[x] = true; //是否在栈中
    stk[++top] = x;
    for (int i = 0; i < a[x].size(); i++) {
        int temp = a[x][i];
        if (!dfn[temp]) {
            Tarjan(temp);
            low[x] = min(low[x], low[temp]);
        } else if (vis[temp])
            low[x] = min(low[x], dfn[temp]);
    }
    if (dfn[x] == low[x]) { //构成强连通分量
        vis[x] = false;
        clr[x] = ++col_num; //染色
        while (stk[top] != x) { //清空
            clr[stk[top]] = col_num;
            vis[stk[top--]] = false;
        }
        top--;
    }
}
void delall(int x){
    use[x]=2;
    for(int i=0;i<scc[x].size();i++){
        int t=scc[x][i];
        for(int j=0;j<ra[t].size();j++)
            if(use[clr[ra[t][j]]]!=2){
                delall(clr[ra[t][j]]);
            }
    }
}
int b[3];
int in[10005];
char c[3][5];
int main()
{
    int i, j, s, t, k,n,state = 1;
    scanf("%d%d", &k, &n);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 3; j++)
            scanf("%d%s", &b[j], &c[j]);
        for (j = 0; j < 3; j++) {
            a[b[j] + k * (c[j][0] == 'B')].push_back(b[(j + 1) % 3] + k * (c[(j + 1) % 3][0] == 'R'));
            a[b[j] + k * (c[j][0] == 'B')].push_back(b[(j + 2) % 3] + k * (c[(j + 2) % 3][0] == 'R'));
            ra[b[(j + 1) % 3] + k * (c[(j + 1) % 3][0] == 'R')].push_back(b[j] + k * (c[j][0] == 'B'));
            ra[b[(j + 2) % 3] + k * (c[(j + 2) % 3][0] == 'R')].push_back(b[j] + k * (c[j][0] == 'B'));
        }
    }
    Tarjan_init();
    for (i = 1; i <= k * 2; i++)
        if (clr[i] == 0)
            Tarjan(i);
    for(i=1;i<=k;i++)
        if(clr[i]==clr[i+k])state=0;
    if(state==0){printf("-1\n");return 0;}
    for(i=1;i<=k*2;i++)scc[i].clear();
    memset(in, 0, sizeof(in));
    for(i=1;i<=k*2;i++){
        scc[clr[i]].push_back(i);
        for(j=0;j<ra[i].size();j++)
            if(clr[ra[i][j]]!=clr[i])in[clr[ra[i][j]]]++;
    }
    while(!q.empty())q.pop();
    for(i=1;i<=col_num;i++)
        if(in[i]==0)q.push(i);
    memset(use,0,sizeof(use));
    while(!q.empty()){
        s=q.front();q.pop();
        if(use[s]==2)continue;
        use[s]=1;
        for(i=0;i<scc[s].size();i++){
            t=scc[s][i];
            //printf("%d\n",t);
            for(j=0;j<ra[t].size();j++)
                if(clr[ra[t][j]]!=s){
                    in[clr[ra[t][j]]]--;
                    //printf("%d %d\n",clr[ra[t][j]],in[clr[ra[t][j]]]);
                    if(in[clr[ra[t][j]]]==0){
                        q.push(clr[ra[t][j]]);
                    }
                }
            if(t<=k)t+=k;else t-=k;
            delall(clr[t]);
        }   
    }
    /*for(i=1;i<=k*2;i++){
        printf("%d(%d)(%d): ",i,clr[i],use[clr[i]]);
        for(j=0;j<ra[i].size();j++)printf("%d ",ra[i][j]);
        printf("\n");
    }*/
    if(state==0){
        printf("-1\n");
    }else{
        for(i=1;i<=k;i++)
            if(use[clr[i]]==1)
                printf("B");
            else
                printf("R");
        printf("\n");
    }
    return 0;
}