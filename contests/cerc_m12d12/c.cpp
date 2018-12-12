#include<bits/stdc++.h>
using namespace std;
char c[50];
int a[50];
int n,ans;
int check(){
    for(int i=0;i<n;i++)
        if(a[i]==0)
            return 0;
    return 1;
}
void dfs(int step,int maxi){
    if(check()){
        ans=min(ans,step);
        return;
    }
    if(step>=ans)return;
    int tmp[50];
    for(int i=0;i<n;i++)tmp[i]=a[i];
    for(int i=maxi;i>=1;i--){
        for(int j=0;i+j<n;j++)
            a[i+j]=a[i+j]|tmp[j];
        dfs(step+1,maxi);
        memcpy(a,tmp,sizeof(tmp));
        //for(int j=0;j<n;j++)a[j]=tmp[j];
    }
}
int main(){
    int i,j,k,s,t;
    scanf("%s",c);
    n=strlen(c);
    for(i=0;i<n;i++)
        if(c[i]=='1')a[i]=1;
        else a[i]=0;
    if(a[0]==0){
        printf("-1\n");
        return 0;
    }
    ans=6;
    dfs(0,n/2);
    printf("%d\n",ans);
    return 0;
}