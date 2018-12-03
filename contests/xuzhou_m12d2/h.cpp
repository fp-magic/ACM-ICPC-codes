#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int x,idx,flag,r;
    bool operator < (const node& nd)const{
        return x<nd.x;
    }
}a[400005];
int ans[200005];
queue<int>c;
queue<node>q;
int main()
{
    int tt,n,m,i,j,k,s,t,cnt;
    int anslen,now;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&k);
        cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&s,&t);
            a[cnt++]={s,i,1,t};
            a[cnt++]={t,i,-1,-1};
        }
        sort(a,a+cnt);
        now=0;anslen=0;
        for(i=1;i<=n;i++)ans[i]=0;
        while(!q.empty())q.pop();
        while(!c.empty())c.pop();
        for(i=1;i<=k;i++)c.push(i);
        for(i=0;i<cnt;i++){
            if(now>=k){
                anslen+=a[i].x-a[i-1].x;
            }//printf("%d %d\n",a[i].x,a[i].flag);
            if(a[i].flag==1){
                if(now<k){
                    ans[a[i].idx]=c.front();
                    c.pop();
                    now++;
                }else
                    q.push(a[i]);
            }else{
                if(ans[a[i].idx]){
                    bool addnew=0;
                    while(!q.empty()){
                        if(q.front().r>a[i].x){
                            ans[q.front().idx]=ans[a[i].idx];
                            addnew=1;
                            q.pop();
                            break;
                        }else
                            q.pop();
                    }
                    if(!addnew){
                        c.push(ans[a[i].idx]);
                        now--;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
            if(!ans[i]){
                ans[i]=1;
            }
        printf("%d\n",anslen);
        for(i=1;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}