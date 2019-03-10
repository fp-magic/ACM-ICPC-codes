#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int p[100005],flag[100005];
int fin(int x){if(p[x]!=x)p[x]=fin(p[x]);return p[x];}
int unio(int x,int y){int px=fin(x),py=fin(y);p[px]=py;}
int main(){
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    for(i=1;i<=10005;i++)p[i]=i;
    memset(flag,0,sizeof(flag));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&m);
        scanf("%d",&k);
        flag[k]=1;
        for(j=2;j<=m;j++)
        {
            scanf("%d",&s);
            flag[s]=1;
            unio(k,s);
        }
    }
    s=0;
    for(i=1;i<=10005;i++)s+=flag[i];
    t=0;
    for(i=1;i<=10005;i++)if(fin(i)==i&&flag[i])t++;
    printf("%d %d\n",s,t);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&s,&t);
        if(fin(s)==fin(t))printf("Y\n");
        else printf("N\n");
    }
    return 0;
}