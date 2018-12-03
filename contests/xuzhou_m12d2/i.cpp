#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
#define ull unsigned long long
int n,k,q,ans;
int a[16][2];
set<vector<int> >mp;
void dfs(vector<int>&num,int step)
{//printf("!");
    if(step==0)
    {
        //mp.insert(num);
        ans++;
        return;
    }
    if(num[a[step][0]]>num[a[step][1]])return;
    dfs(num,step-1);
    swap(num[a[step][0]],num[a[step][1]]);
    dfs(num,step-1);
    swap(num[a[step][0]],num[a[step][1]]);
}
int main()
{
    int tt,m,i,j,s,t;
    vector<int>tmp;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(i=1;i<=k;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
            a[i][0]--;a[i][1]--;
        }
        ans=0;
        mp.clear();
        tmp.clear();
        for(i=0;i<n;i++)
            tmp.push_back(i);
        dfs(tmp,k);
        for(i=n-2;i>=0;i--)
        {
            swap(tmp[i],tmp[i+1]);
            dfs(tmp,k);
        }
        for(i=n-2;i>=0;i--)
        {
            tmp.clear();
            for(j=0;j<n;j++)
                tmp.push_back(j);
            for(j=i-1;j>=0;j--)
            {
                swap(tmp[j],tmp[j+1]);
                dfs(tmp,k);
            }
            tmp.clear();
            for(j=0;j<n;j++)
                tmp.push_back(j);
            swap(tmp[i],tmp[i+1]);
            for(j=i+2;j<n;j++)
            {
                swap(tmp[j-1],tmp[j]);
                dfs(tmp,k);
            }
        }
        printf("%d\n",ans%q);
    }
    return 0;
}