#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[1005];
int main()
{
    int n,m,i,j,k,s,t,flag;
    while(scanf("%d",&n)!=EOF)
    {
        flag=1;
        for(i=1;i<=n;i++)
        {
            scanf("%s",ch);
            if(ch[0]!='m')
            {
                t=0;
                s=strlen(ch);
                for(j=0;j<s;j++)
                    t=t*10+ch[j]-'0';
                if(t!=i)flag=0;//printf("%d %d\n",i,t);
            }
        }
        if(flag)
            printf("makes sense\n");
        else
            printf("something is fishy\n");
    }
    return 0;
}