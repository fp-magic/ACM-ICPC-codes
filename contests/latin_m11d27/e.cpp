#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
char ch[1005];
int a[1005];
vector<int>b;
int main()
{
    int n,i,j,k,s,t,p1,p2,p3,p4,ii,jj;
    scanf("%s",ch);
    scanf("%d",&n);
    a[0]=1%n;
    for(i=1;i<=1000;i++)
    {
        a[i]=a[i-1]*10%n;
    }
    k=strlen(ch);
    t=0;
    for(i=k-1;i>=0;i--)
    {
        if(ch[i]=='?')
        {
            if(b.size()<4)
                b.push_back(k-1-i);
            else
            {
                if(i==0)
                {
                    ch[i]='1';
                    t=(t+a[k-1-i]*(ch[i]-'0'))%n;
                }else
                    ch[i]='0';
            }
        }else
            t=(t+a[k-1-i]*(ch[i]-'0'))%n;
    }
    s=-1;
    if(b.size()==0)
    {
        if(t%n==0)s=1;
    }else
    if(b.size()==1)
    {
        for(i=0;i<=9;i++)
        if((t+i*a[b[0]])%n==0)
        {
            if(k-1-b[0]==0&&i==0)continue;
            s=1;
            ch[k-1-b[0]]=i+'0';
            break;
        }
    }else
    if(b.size()==2)
    {
        for(i=0;i<=9&&s==-1;i++)
            for(j=0;j<=9&&s==-1;j++)
            if((t+i*a[b[1]]+j*a[b[0]])%n==0)
            {
                if(k-1-b[1]==0&&i==0)continue;
                s=1;
                ch[k-1-b[1]]=i+'0';
                ch[k-1-b[0]]=j+'0';
            }
    }else
    if(b.size()==3)
    {
        for(ii=0;ii<=9&&s==-1;ii++)
        for(i=0;i<=9&&s==-1;i++)
            for(j=0;j<=9&&s==-1;j++)
            if((t+ii*a[b[2]]+i*a[b[1]]+j*a[b[0]])%n==0)
            {
                if(k-1-b[2]==0&&ii==0)continue;
                s=1;
                ch[k-1-b[2]]=ii+'0';
                ch[k-1-b[1]]=i+'0';
                ch[k-1-b[0]]=j+'0';
            }
    }else
    if(b.size()==4)
    {
        for(jj=0;jj<=9&&s==-1;jj++)
        for(ii=0;ii<=9&&s==-1;ii++)
        for(i=0;i<=9&&s==-1;i++)
            for(j=0;j<=9&&s==-1;j++)
            if((t+jj*a[b[3]]+ii*a[b[2]]+i*a[b[1]]+j*a[b[0]])%n==0)
            {
                if(k-1-b[3]==0&&jj==0)continue;
                s=1;
                ch[k-1-b[3]]=jj+'0';
                ch[k-1-b[2]]=ii+'0';
                ch[k-1-b[1]]=i+'0';
                ch[k-1-b[0]]=j+'0';
            }
    }
    if(s==-1)printf("*\n");
    else printf("%s\n",ch);
    return 0;
}