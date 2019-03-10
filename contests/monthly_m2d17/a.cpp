
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,i;
    int a[20];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)a[i]=i+1;
        do
        {
            for(i=0;i<n-1;i++)printf("%d",a[i]);
            printf("%d\n",a[n-1]);
        }while(next_permutation(a,a+n));
    }
    return 0;
}