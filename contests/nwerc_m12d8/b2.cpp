#include <bits/stdc++.h>
using namespace std;
vector<int>a[400005];
int n;
int out[400005],w[400005];
struct node{
    int x,idx;
    bool operator < (const node& r)const{
        return x>r.x;
    }
}b[400005];
priority_queue<node>q;
int main(){
    int i,j,k,s,t,ans=0;
    for(i=1;i<=n;i++)a[i].clear();
    memset(out,0,sizeof(w));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i],&s);
        b[i].idx=i;b[i].x=w[i];
        while(s--){
            scanf("%d",&t);
            out[t]++;
            a[i].push_back(t);    
        }
    }
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++)
    if(out[i]==0)
        q.push(b[i]);
    t=n-1;
    //for(i=1;i<=n;i++)printf("%d ",out[i]);printf("\n");
    while(!q.empty()){
        node tmp=q.top();q.pop();
        //printf("=%d %d\n",tmp.idx,tmp.x);
        ans=max(ans,tmp.x+t);
        t--;
        for(i=0;i<a[tmp.idx].size();i++){
            out[a[tmp.idx][i]]--;//printf("--%d %d\n",a[tmp.idx][i],out[a[tmp.idx][i]]);
            if(out[a[tmp.idx][i]]==0){
                q.push(b[a[tmp.idx][i]]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}