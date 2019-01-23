#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char a[105];
char ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    char ch;
    scanf("%s",a);
    return a[0];
}
void ans(int x){
    printf("! %d\n",x);
    fflush(stdout);
}
int main(){
    char ch;
    int n,m,x,y,d,i,j,k,s,t,tt,l,r,st;
    while(scanf("%s",a)!=EOF){
        if(a[0]=='e'||a[0]=='m')
            break;
        st=0;
        l=1;r=2e9;s=1;t=2;
        do
        {//printf("%d %d %d %d\n",l,r,s,t);
            ch=ask(s,t);
            //printf("=%c=\n",ch);
            if(ch=='x')
            {//puts("!");
                r=t;
                s=l-1;
                t=l+(r-l)/2;
                st=1;
            }else
            if(ch=='y')
            {//puts("?");
                l=min(t+1,r);
                if(!st)
                {
                    s=l;
                    t=min(2*s,r);
                }else
                {
                    s=l-1;
                    t=l+(r-l)/2;
                }
            }else break;
            if(l==r)
            {
                ans(l);
                break;
            }
        }while(l!=r);
        if(l!=r)break;
    }
    return 0;
}