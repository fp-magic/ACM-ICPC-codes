#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char c[1005];
int main()
{
    int n,m,x,y,d,i,j,k,s,t,tt;
    scanf("%s",c);
    k=strlen(c);
    s=0;t=0;
    for(i=0;i<k;i++){
        if(c[i]=='0')
        {
            if(s==0)
                printf("3 4\n");
            else
                printf("1 4\n");
            s=(s+1)%2;
        }else
        {
            if(t==0)
                printf("1 1\n");
            else
                printf("1 3\n");
            t=(t+1)%2;
        }
    }
    return 0;
}