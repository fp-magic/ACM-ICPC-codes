#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
char a[10005],b[10005];
int is(char c)
{
    if(c=='a'||c=='i'||c=='e'||c=='o'||c=='u')return 1;
    return 0;
}
int main()
{
    int n,m,i,j,k,s,t;
    scanf("%s",a);
    scanf("%s",b);
    s=strlen(a);
    t=strlen(b);
    if(s!=t)
    {
        printf("No\n");
    }else
    {
        for(i=0;i<s;i++)
        if(is(a[i])!=is(b[i]))
        {
            printf("No\n");
            return 0;
        }
        printf("Yes\n");
    }
    return 0;
}