#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int a[100005][2];
int b[200005];
map<int,int>mp,mp2;
vector<int>f[200005],g[200005];
int main(){
    int tt,n,m,i,j,k,s,t,ans,fm,gm,step=0;
    long long ansnum;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d%d",&a[i][0],&a[i][1]);
            b[i*2]=a[i][0];
            b[i*2+1]=a[i][1];
        }
        sort(b,b+n*2);
        mp.clear();
        t=0;
        for(i=0;i<n*2;++i){
            if(i==0||b[i]>b[i-1]){
                mp.insert(make_pair(b[i],t++));
            }
        }
        for(i=0;i<n;++i)
            a[i][0]=mp[a[i][0]],a[i][1]=mp[a[i][1]];
        for(i=0;i<n*2;++i)
            f[i].clear(),g[i].clear();
        for(i=0;i<n;++i)
            f[a[i][0]].push_back(a[i][1]),g[a[i][1]].push_back(a[i][0]);
        fm=0;gm=0;
        for(i=0;i<n*2;++i)
            fm=max(fm,(int)f[i].size()),gm=max(gm,(int)g[i].size());
        mp.clear();mp2.clear();
        for(i=0;i<n*2;++i){
            if(g[i].size()==gm)
                mp.insert(make_pair(i,1));
            if(g[i].size()==gm-1)
                mp2.insert(make_pair(i,1));
        }
        ans=fm+gm-1;ansnum=0;
        for(i=0;i<n*2;++i)
            if(f[i].size()==fm){
                t=0;
                for(j=0;j<f[i].size();++j)
                    if(mp.count(f[i][j]))t++;
                if(t<mp.size()){
                    ans=fm+gm;
                    break;
                }
            }
        if(ans==fm+gm-1){
            for(i=0;i<n*2;++i){
                if(f[i].size()==fm){
                    ansnum+=mp2.size();               
                    for(j=0;j<f[i].size();++j){
                        if(mp.count(f[i][j]))ansnum++;
                        if(mp2.count(f[i][j]))ansnum--;
                    }
                }
                if(f[i].size()==fm-1){
                    ansnum+=mp.size();
                    for(j=0;j<f[i].size();++j)
                        if(mp.count(f[i][j]))ansnum--;
                }
            }
        }else{
            for(i=0;i<n*2;++i){
                if(f[i].size()==fm){
                    ansnum+=mp.size();
                    for(j=0;j<f[i].size();++j)
                        if(mp.count(f[i][j]))ansnum--;
                }
            }
        }
        if(fm==1&&gm==1)ansnum/=2;
        if(fm==0||gm==0)ansnum=1;
        printf("Case %d: %d %I64d\n",++step,ans,ansnum);
    }
    return 0;
}