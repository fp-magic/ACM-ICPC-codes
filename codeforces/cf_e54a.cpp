#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200005];
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    scanf("%s",a);
    k=n-1;
    for(i=0;i<n-1;i++)
    if(a[i]>a[i+1])
    {
        k=i;
        break;
    }
    for(i=0;i<n;i++)
    if(i!=k)printf("%c",a[i]);printf("\n");
    return 0;
}