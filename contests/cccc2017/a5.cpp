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
vector<int>a[10005],b[10005];
int line[10005];
int prea[10005],preb[10005];
int n;
queue<int>q;
int disa[10005][105],disb[10005][105],vis[10005];
void spfa(int s,int t){
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    q.push(s);
    for(i=1;i<=n;i++)disa[i]=1000000,disb[i]=1000000;
    prea[s]=0;preb[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<a[x].size();i++)
        {
            if(disa[a[x][i]]<disa[x]+1||(disa[a[x][i]]==disa[x]+1&&disb[a[x][i]]<disb[x]+(preb[s])))
        }
    }
}
int main()
{
    int m,i,j,k,s,t;
    scanf("%d",&n);
    for(i=0;i<10000;i++)a[i].clear(),b[i].clear();
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&line[j]);
        }
        for(j=2;j<=m;j++)
        {
            a[line[j-1]].push_back(line[j]);
            b[line[j-1]].push_back(i);
            a[line[j]].push_back(line[j-1]);
            b[line[j]].push_back(i);
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&s,&t);
        spfa(s,t);
    }
    return 0;
}