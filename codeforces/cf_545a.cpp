#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
ll mod = 1e9+7;
int a[1005][1005];
int x[1005][1005],y[1005][1005],cx[1005],cy[1005];
pair<int,int>b[1005];
int main()
{
    int n,m,i,j,k,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(y,127,sizeof(y));
    memset(x,127,sizeof(x));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            b[j].fr=a[i][j],b[j].sc=j;
        sort(b+1,b+m+1);
        k=0;
        for(j=1;j<=m;j++)
        {
            if(j==1||b[j].fr>b[j-1].fr)k++;
            x[i][b[j].sc]=k;
        }
        cx[i]=k;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            b[j].fr=a[j][i],b[j].sc=j;
        sort(b+1,b+n+1);
        k=0;
        for(j=1;j<=n;j++)
        {
            if(j==1||b[j].fr>b[j-1].fr)k++;
            y[b[j].sc][i]=k;
        }
        cy[i]=k;
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            printf("(%d %d)",x[i][j],y[i][j]);
        printf("\n");
    }*/
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("%d ",max(x[i][j],y[i][j])+max(cx[i]-x[i][j],cy[j]-y[i][j]));
        }
        printf("\n");
    }
    return 0;
}