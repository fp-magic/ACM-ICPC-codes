#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct gjd
{
    int a[1005];
    int len;
    gjd()
    {
        memset(a,0,sizeof(a));
        len=0;
    }
    bool operator < (gjd &r)
    {
        if(len>r.len)return 0;
        if(len<r.len)return 1;
        int i;
        for(i=len;i>=0;i--)
            if(a[i]!=r.a[i]||i==0)break;
        return a[i]<r.a[i];
    }
    bool operator == (gjd &r)
    {
        if(len>r.len)return 0;
        if(len<r.len)return 0;
        int i;
        for(i=len;i>=0;i--)
            if(a[i]!=r.a[i]||i==0)break;
        return a[i]==r.a[i];
    }
    gjd operator+(gjd &r)
    {
        gjd tmp;
        tmp.a[0]=(a[0]+r.a[0])%10;
        tmp.a[1]=(a[0]+r.a[0])/10;
        for(int i=1;i<=max(len,r.len);i++)
        {
            tmp.a[i+1]+=(tmp.a[i]+a[i]+r.a[i])/10;
            tmp.a[i]=(tmp.a[i]+a[i]+r.a[i])%10;
        }
        tmp.len=max(len,r.len);
        if(tmp.a[tmp.len+1])tmp.len++;
        return tmp;
    }
    void output()
    {
        printf("%d->\n",len);
        for(int i=len;i>=0;i--)printf("%d ",a[i]);
        printf("\n");
    }
}b[1005],sum,now;
char a[1005][25];
char ch[1005];
int flag[1005];
int vit[1005];
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    scanf("%s",ch);
    k=strlen(ch);
    sum.len=k-1;
    for(j=0;j<k;j++)
        sum.a[k-1-j]=ch[j]-'0';
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        scanf("%s",ch);   
        k=strlen(ch);
        b[i].len=k-1;
        for(j=0;j<k;j++)
            b[i].a[k-1-j]=ch[j]-'0';
    }
    s=0;
    memset(vit,0,sizeof(vit));
    for(j=1;j<=n;j++)
    {
        t=0;
        for(i=1;i<=n;i++)
        if(!vit[i])
        {
            if(t==0||b[t]<b[i])t=i;
        }
        vit[t]=1;//printf("!%d\n",t);
        if((b[t]+now)<sum||(b[t]+now)==sum)
        {
            now=now+b[t];
            flag[t]=1;
            s++;
        }
    }
    if(now==sum)
    {
        printf("%d\n",s);
        for(i=1;i<=n;i++)
        if(flag[i])
            printf("%s\n",a[i]);
    }else
        printf("0\n");
    return 0;
}