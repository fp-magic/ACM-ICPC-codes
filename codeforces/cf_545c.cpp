#include<cstring>
#include<vector>
#include<cstdio>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
const int maxn=5e6+5;
struct edge{
    int next,to;
}q[maxn];
int head[maxn],dfn[maxn],low[maxn],cnt,tot;
int vis[maxn],belong[maxn],index,belong_num[maxn],num_index;
int indegree[maxn],outdegree[maxn];
void add_edge(int from,int to){
    q[cnt].next=head[from];
    q[cnt].to=to;
    head[from]=cnt++;
}
void init(){//初始化
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
    memset(head,-1,sizeof(head));
    memset(low,0,sizeof(low));
    memset(belong_num,0,sizeof(belong_num));
    memset(indegree,0,sizeof(indegree));
    memset(outdegree,0,sizeof(outdegree));
    index=num_index=cnt=tot=0;
}
stack<int>st;
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    vis[x]=1;
    st.push(x);
    for(int i=head[x];i!=-1;i=q[i].next){
        edge e=q[i];
        if(!dfn[e.to]){
            tarjan(e.to);
            low[x]=min(low[e.to],low[x]);
        }
        else if(vis[e.to]==1){
            low[x]=min(low[x],dfn[e.to]);
        }
    }
    if(dfn[x]==low[x]){
        int v;
        index=index+1;
        do{
            v=st.top();
            st.pop();
            belong[v]=index;
            belong_num[index]++;
            vis[v]=0;
        }while(v!=x);
    }
}
char a[100005][52];
int num[5000005],f[5000005];
vector<int>b[5000005];
map<int,int>mp;
int dfs(int x){//printf("%d ",x);
    int ans=0;
    for(int i=0;i<b[x].size();i++)
        ans=max(ans,dfs(b[x][i]));
    return ans+f[x];
}
int main()
{
    init();
    int n,m,d,i,j,k,s,t,ans;
    scanf("%d%d%d",&n,&m,&d);
    for(i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        for(j=0;j<d;j++)add_edge((s-1)*d+j,(t-1)*d+(j+1)%d);
    }
    for(i=0;i<n*d;i++){
        if(!dfn[i])tarjan(i);
        b[i].clear();
    }

    for(i=0;i<n*d;i++){
        for(j=head[i];j!=-1;j=q[j].next){
            if(belong[i]!=belong[q[j].to])b[belong[i]].push_back(belong[q[j].to]);
        }
    }    
    /*for(i=0;i<n*d;i++)
    {
        printf("%d(%d): ",i,belong[i]);
        for(j=head[i];j!=-1;j=q[j].next)printf("%d ",q[j].to);
        printf("\n");
    }*/
    for(i=0;i<n;i++){
        getchar();
        scanf("%s",a[i]);    
    }
    memset(num,0,sizeof(num));
    memset(f,0,sizeof(f));
    for(i=0;i<n;i++)
    {
        mp.clear();
        for(j=0;j<d;j++)
            if(a[i][j]=='1')
            {
                if(!mp.count(belong[i*d+j]))
                {//printf("%d %d: %d %d\n",i,j,i*d+j,belong[i*d+j]);
                    f[belong[i*d+j]]++;
                    mp.insert(make_pair(belong[i*d+j],1));
                }
            }
    }
    /*for(i=0;i<=index;i++)
    {
        printf("%d(%d): ",i,f[i]);
        for(j=0;j<b[i].size();j++)printf("%d ",b[i][j]);
        printf("\n");
    }*/
    ans=0;
    printf("%d\n",dfs(belong[0]));
    return 0;
}