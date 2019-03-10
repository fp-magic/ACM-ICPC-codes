#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;
int a[505][505],b[505];
map<int,int>mp;
int main()
{
    int n,m,q,i,j,k,s,t;
    scanf("%d%d%d",&n,&m,&k);
    memset(a,0,sizeof(a));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&s,&t);
        a[s][t]=a[t][s]=1;
    }
    scanf("%d",&q);
    while(q--)
    {
        mp.clear();
        for(j=1;j<=n;j++)
            scanf("%d",&b[j]),mp[b[j]]=1;
        t=1;
        for(j=1;j<=n;j++)
            if(b[j]<1||b[j]>v)t=0;
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        if(a[i][j]&&b[i]==b[j])t=0;
        if(t)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}