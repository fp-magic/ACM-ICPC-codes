#include<bits/stdc++.h>
using namespace std;
int a[500005][2];
int p[500005];
int ans[500005];
int main(){
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i=0;i<n;++i){
        scanf("%d",&s);
        if(s==1){
            scanf("%d",&a[i][0]);
        }else{
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
    }
    m=0;
    for(i=0;i<500005;++i)p[i]=i;
    for(i=n-1;i>=0;--i){
        if(a[i][1]==0){
            ans[m++]=p[a[i][0]];
        }else{
            p[a[i][0]]=p[a[i][1]];
        }
    }
    for(i=m-1;i>=0;--i){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}