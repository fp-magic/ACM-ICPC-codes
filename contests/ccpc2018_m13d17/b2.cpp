#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
int a[200005][2];
int p[400005];
vector<int>b[400005];
pair<pair<int,int>,int>c[800005],d[800005];
int flag[200005][4];
int vit[400005];
int fin(int x){if(p[x]!=x)p[x]=fin(p[x]);return p[x];}
void unio(int x,int y){
    int px=fin(x),py=fin(y);p[px]=py;
}
bool ok(int dis,int tot){
    int i,j,l,r,now=0;printf("=====%d %d\n",tot/4,dis);
    /*for(i=0;i<tot/4;++i){
        flag[i][0]=0;flag[i][1]=0;flag[i][2]=0;flag[i][3]=0;
    }*/memset(flag,0,sizeof(flag));
    pair<int,int>s;
    j=0;
    for(i=0;i<tot;++i){
        if(flag[c[i].second/4][0]+flag[c[i].second/4][1]<2&&flag[c[i].second/4][2]+flag[c[i].second/4][3]<2){
            if(flag[c[i].second/4][(c[i].second%4)^1])now++;
        }
        if(dis<=5)printf("%d %d\n",c[i].second,now);
        flag[c[i].second/4][c[i].second%4]=1;
        while(d[j].first.first<c[i].first.first-dis){
            s=d[j].first;j++;
            if(flag[s.second/4][(s.second%4)^1]&&((flag[s.second/4][((s.second%4|1)+1)%4]+flag[s.second/4][((s.second%4|1)+2)%4]<2))){
                now--;
            }
            printf("-%d",s.second);
            flag[s.second/4][s.second%4]=0;
        }
        if(dis<=5)printf("=%d %d\n",c[i].second,now);
        if(now>=tot/4)return true;
    }
    return false;
}
int main(){
    int tt,n,m,i,j,k,s,t,flag,step=0,tot,pl,pr,ql,qr,l,r,mid;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&m);
        flag=1;
        for(i=1;i<=n*2;++i)p[i]=i;
        for(i=1;i<=m;++i){
            scanf("%d%d",&s,&t);
            if(fin(s)==fin(t)||fin(s+n)==fin(t+n))flag=0;
            unio(t+n,s);unio(s+n,t);
        }
        for(i=1;i<=n;++i)scanf("%d%d",&a[i][0],&a[i][1]);
        if(!flag){
            printf("Case %d: IMPOSSIBLE\n",++step);
            continue;
        }
        for(i=1;i<=n*2;++i)b[i].clear();
        for(i=1;i<=n*2;++i)b[fin(i)].push_back(i);
        /*for(i=0;i<=n*2;++i)
        if(b[i].size()){
            printf("%d: ",i);
            for(j=0;j<b[i].size();++j)printf("%d ",b[i][j]);
            printf("\n");
        }*/
        tot=0;
        /*for(i=1;i<=n*2;++i)vit[i]=0;*/memset(vit,0,sizeof(vit));
        for(i=1;i<=n;++i)
            if(b[i].size()){
                pl=1e9+5;ql=1e9+5;pr=0;qr=0;t=1;
                for(j=0;j<b[i].size();++j)if(vit[b[i][j]]){t=0;break;}
                if(t==0)continue;
                for(j=0;j<b[i].size();++j){
                    if(b[i][j]<=n){
                        vit[b[i][j]]=1;vit[b[i][j]+n]=1;
                        //printf("[%d] %d %d\n",b[i][j],a[b[i][j]][0],a[b[i][j]][1]);
                        pl=min(pl,a[b[i][j]][0]);pr=max(pr,a[b[i][j]][0]);
                        ql=min(ql,a[b[i][j]][1]);qr=max(qr,a[b[i][j]][1]);
                    }
                }
                c[tot].first=make_pair(pr,pl);
                c[tot].second=tot;
                c[tot+2].first=make_pair(qr,ql);
                c[tot+2].second=tot+2;
                pl=1e9+5;ql=1e9+5;pr=0;qr=0;t=0;
                for(j=0;j<b[i].size();++j){
                    if(b[i][j]>n){
                        vit[b[i][j]]=1;vit[b[i][j]-n]=1;t=1;
                        //printf("[%d] %d %d\n",b[i][j],a[b[i][j]-n][0],a[b[i][j]-n][1]);
                        pl=min(pl,a[b[i][j]-n][0]);pr=max(pr,a[b[i][j]-n][0]);
                        ql=min(ql,a[b[i][j]-n][1]);qr=max(qr,a[b[i][j]-n][1]);
                    }
                }
                if(t==0){
                    c[tot+1].first=c[tot].first;
                    c[tot+1].second=tot+1;
                    c[tot+3].first=c[tot+2].first;
                    c[tot+3].second=tot+3;
                }else{
                    c[tot+1].first=make_pair(qr,ql);
                    c[tot+1].second=tot+1;
                    c[tot+3].first=make_pair(pr,pl);
                    c[tot+3].second=tot+3;
                }
                tot+=4;
            }
        //for(i=0;i<tot;++i)printf("%d %d :%d\n",c[i].first.first,c[i].first.second,c[i].second);
        for(i=0;i<tot;++i){
            d[i]=c[i];
            swap(d[i].first.first,d[i].first.second);
        }
        sort(d,d+tot);
        sort(c,c+tot);
        //for(i=0;i<tot;++i)printf("%d %d :%d\n",c[i].first.first,c[i].first.second,c[i].second);
        l=0;r=1e9+1;
        while(l<r){
            mid=(l+r)/2;
            if(ok(mid,tot))
                r=mid;
            else
                l=mid+1;
        }
        printf("Case %d: %d\n",++step,l);
    }
    return 0;
}