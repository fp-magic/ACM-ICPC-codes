#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
pair<int,int> a[100005];
int main(){
    int n,m,i,j,k,s,t,tt,step=0;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)scanf("%d",&a[i].first);
        for(i=0;i<n;i++)scanf("%d",&a[i].second);
        sort(a,a+n);
        s=0;t=0;
        while(t<n){
            if(s+a[t].second>m)break;
            s+=a[t].second;
            //printf("%d %d\n",s,m);
            t++;
        }
        printf("Case %d: %d\n",++step,t);
    }
    return 0;
}