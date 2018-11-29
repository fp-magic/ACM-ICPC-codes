#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char a[100005];
vector<int>l,r;
int main()
{
    int n,m,i,j,k,s,t;
    char ch;
    scanf("%d",&n);
    scanf("%s",a);
    l.clear();r.clear();
    if(a[0]=='G')l.push_back(0);
    for(i=1;i<n;i++)
    {
        if(a[i]=='G')
        {
            if(a[i-1]=='S')
                l.push_back(i);
        }else
        {
            if(a[i-1]=='G')  
                r.push_back(i-1);
        }
    }
    if(a[n-1]=='G')r.push_back(n-1);
    s=0;t=0;
    for(i=0;i<l.size();i++)
        s=max(s,r[i]-l[i]+1);
    for(i=1;i<l.size();i++)
    if(l[i]==r[i-1]+2)
    {
        t=max(t,r[i]-l[i-1]+1);
    }
    if(l.size()>=3)
    {
        printf("%d\n",max(s+1,t));
    }else
    if(l.size()==2)
    {
        printf("%d\n",max(s+1,t-1));
    }else
    {
        printf("%d\n",s);
    }
    return 0;
}