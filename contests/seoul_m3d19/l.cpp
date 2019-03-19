#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int state[2005],w[2005],d[2005];
vector<int>a[2005];
queue<pair<int,int> >rest,work;
priority_queue<pair<int,int> >towork;
int main(){
    int n,m,i,j,k,s,t,ww,hh,flag=1,working=0;
    scanf("%d%d%d%d",&m,&n,&ww,&hh);
    memset(w,0,sizeof(w));
    memset(d,0,sizeof(d));
    for(i=1;i<=m;i++)scanf("%d",&w[i]),w[i]/=ww;
    for(i=1;i<=n;i++)scanf("%d",&d[i]);
    for(i=1;i<=m;i++)a[i].clear();
    memset(state,0,sizeof(state));
    for(i=1;i<=m;i++)towork.push(make_pair(w[i],i));
    for(i=1;i<=n+1;i++){
        //printf("%d: ",i);
        //    for(k=1;k<=m;k++)printf("%d ",state[k]);
        //    printf("\n");
        for(j=1;j<=m;j++)
        {
            
            if(state[j]>0&&i-state[j]==ww){
                a[j].push_back(state[j]);
                w[j]--;
                state[j]=-i;
                working--;
            }
        }//printf("=%d",working);
        for(j=1;j<=m;j++)
        {
            if(state[j]<0&&(state[j]+i)>=hh&&w[j]>0){
                state[j]=0;
                towork.push(make_pair(w[j],j));
            }
        }
        if(working>d[i])flag=0;
        k=working;
        for(j=1;j<=d[i]-k;j++){
            if(towork.empty()){flag=0;break;}
            s=towork.top().second;towork.pop();
            state[s]=i;
            working++;
        }
        if(flag==0)break;
    }
    for(i=1;i<=m;i++)if(w[i]!=0)flag=0;
    if(flag==0){
        printf("-1\n");
    }else{
        printf("1\n");
        for(i=1;i<=m;i++){
            for(j=0;j<a[i].size();j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}