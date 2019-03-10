#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int a[10000];
int main()
{
    int n,i,j,k,s,t,u,v;
    char ch;
    scanf("%d",&n);
    memset(a,255,sizeof(a));
    u=0;v=0;
    while(n)
    {
        scanf("%d %c %d:%d",&k,&ch,&s,&t);
        if(k==0)
        {
            n--;
            printf("%d %.0f\n",u,u==0?0:(double)v/(double)u);
            memset(a,255,sizeof(a));
            u=0;v=0;
            continue;
        }
        if(ch=='S')
        {
            a[k]=s*60+t;
        }
        if(ch=='E')
        {
            if(a[k]>=0)
            {
                u++;
                v+=s*60+t-a[k];
                a[k]=-1;
            }
        }
    }
    return 0;
}