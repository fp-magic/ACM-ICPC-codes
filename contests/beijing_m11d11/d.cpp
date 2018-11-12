#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a,b;
int main()
{
    int n,m,i,j,k,s,t,tot;
    while(scanf("%d",&m)!=EOF)
    {
        a.clear();b.clear();
        t=0;tot=0;
        for(i=0;i<=31;i++)
        if(m&(1<<i))
        {
            a.push_back(t+1);
            b.push_back(199);
            tot++;
            a.push_back(t+5);
            b.push_back(t+5);
            tot++;
            t=t+6;
        }else
        {
            a.push_back(t+3);
            b.push_back(t+3);
            tot++;
            t=t+4;
        }
        for(i=196;i<=198;i++)
        {
            a.push_back(i);
            b.push_back(i);
            tot++;
        }
        printf("%d\n",tot);
        for(i=0;i<tot;i++)
        {
            printf("%d %d\n",a[i],b[i]);
        }
    }
    return 0;
}