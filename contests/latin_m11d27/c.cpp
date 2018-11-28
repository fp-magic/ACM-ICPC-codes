#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int a[10005];
vector<int>b[10005];
int main()
{
    int flag,k,n,i,j,s,t,mi,ma,di;
    scanf("%d%d",&k,&n);
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)b[i].clear();
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[t]++;
    }
    mi=a[0];ma=a[0];
    for(i=1;i<=k;i++)
    {
        b[a[i]].push_back(i);
    }
    if(n%k==0)di=n/k;
    else if(n%k==1)di=(n-1)/k;
    else if(n%k==k-1)di=(n+1)/k;
    for(i=1;i<=n;i++)
    if((i>di+1||i<di-1)&&b[i].size())
    {
        printf("*\n");
        return 0;
    }
    if(n%k==0)
    {    
        if(b[n/k-1].size()==1&&b[n/k+1].size()==1)
            printf("-%d +%d\n",b[n/k+1][0],b[n/k-1][0]);       
        else
        if(b[n/k-1].size()==0&&b[n/k+1].size()==0)
            printf("-%d +%d\n",b[n/k][0],b[n/k][0]);
    }else
    if(n%k==1&&b[di-1].size()==0&&b[di+1].size()==1)
        printf("-%d\n",b[di+1][0]);
    else
    if(n%k==k-1&&b[di+1].size()==0&&b[di-1].size()==1)
        printf("+%d\n",b[di-1][0]);
    else
        printf("*\n");
    return 0;
}