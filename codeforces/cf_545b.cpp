#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
char a[500005];
char b[500005];
int Next[500005];
int main()
{
    int n,m,i,j,k,s,t,num0=0,num1=0,one0=0,one1=0,more0=0,more1=0;
    scanf("%s",a);
    scanf("%s",b);
    s=strlen(a);
    for(i=0;i<s;++i){
        if(a[i]=='0')num0++;
        if(a[i]=='1')num1++;
    }
    s=strlen(b);
    for(i=0;i<s;++i){
        if(b[i]=='0')one0++;
        if(b[i]=='1')one1++;
    }
    i=0;j=-1;Next[0]=-1;
    while(i<s){
        if(j==-1||b[i]==b[j]){++i,++j,Next[i]=j;}
        else j=Next[j];
    }
    //for(i=0;i<=s;i++)printf("%d ",Next[i]);printf("\n");
    for(i=Next[s];i<s;++i){
        if(b[i]=='0')more0++;
        if(b[i]=='1')more1++;
    }
    if(num0>=one0&&num1>=one1)
        k=1+min(more0==0?500001:(num0-one0)/more0,more1==0?500001:(num1-one1)/more1);
    else
        k=0;
    //printf("!%d\n",k);
    if(k==0)
        printf("%s\n",a);
    else
    {
        printf("%s",b);
        for(i=2;i<=k;++i)
            for(j=Next[s];j<s;++j)
                printf("%c",b[j]);
        for(i=0;i<num0-(one0+more0*(k-1));++i)
            printf("0");
        for(i=0;i<num1-(one1+more1*(k-1));++i)
            printf("1");
        printf("\n");
    }
    return 0;
}