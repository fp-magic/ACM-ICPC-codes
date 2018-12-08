#include<cstdio>
#include<cstring>
using namespace std;
int a[500005];
char ch[500005];
int main(){
    int n,c,b,i,j,k,s,t,l,r;
    memset(ch,0,sizeof(ch));
    memset(a,0,sizeof(a));
    scanf("%d%d%d",&n,&c,&b);
    for(i=1;i<=b;i++){
        scanf("%d",&t);
        a[t]=1;
        ch[t]='0';
    }
    for(i=1;i<=n;i++)ch[i]='0';
    i=n;
    if(a[n]==0){
        while(a[i]==0)i--;
        r=n;l=i+1;
        for(j=l;j<=r;j++){
            if(c>=2&&j<n){
                ch[j]='1';
                ch[++j]='0';
                c-=2;//puts("?");
            }
        }
    }
    for(;i>=1;i--){
        if(a[i]==0){
            r=i;
            //printf("%d\n",i);
            while(i>=1&&a[i]==0)i--;
            l=i+1;
            //printf("%d %d\n",l,r);
            for(j=r;j>=l;j--){
                if(c>=2&&j>1){
                    ch[j]='1';
                    ch[--j]='0';
                    c-=2;//puts("!");
                }
            }
        }
    }
    if(c>=1&&n>=2&&ch[2]=='0'){
        ch[1]='1';
        c--;
    }else
        ch[1]='0';
    if(c>=1&&ch[n]=='0'&&ch[n-1]=='0'){
        c--;
        ch[n]='1';
    }
    for(i=1;i<=n;i++)
        printf("%c",ch[i]);
    printf("\n");
    return 0;
}