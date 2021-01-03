#include<cstdio>
#include<cstring>
using namespace std;
char a[105];
int main(){
    int tt,n,m,i,j,k,s,t;
    scanf("%d",&tt);
    while(tt--){
        getchar();
        scanf("%s",a);
        k=strlen(a);
        if(k%2!=0||a[0]==')'||a[k-1]=='('){
            printf("NO\n");
        }else if (k==2 && !(a[0]=='('&&a[1]==')')){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}