#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105];
int b[105];
int f[105][105];
int main(){
    int tt,n,m,i,j,k,s,t;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(i=1;i<=m;++i){
            scanf("%d",&b[i]);
        }
        memset(f,0,sizeof(f));
        s=0;
        f[0][0]=0;
        for(i=1;i<=n;++i){
            f[i][0]=f[i-1][0]+a[i];
        }
        for(j=1;j<=m;++j){
            f[0][j]=f[0][j-1]+b[j];
        }
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                f[i][j]=max(f[i-1][j]+a[i],f[i][j-1]+b[j]);
            }
        }
        for(i=0;i<=n;++i)
            for(j=0;j<=m;++j)
                s=max(s,f[i][j]);
        printf("%d\n",s);
    }
    return 0;
}