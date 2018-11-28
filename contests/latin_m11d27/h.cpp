#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int a[3];
int main()
{
    int i,s=0,t;
    for(i=0;i<3;i++)scanf("%d",&a[i]);
    for(i=0;i<3;i++)scanf("%d",&t),s+=t>a[i]?t-a[i]:0;
    printf("%d\n",s);
    return 0;
}