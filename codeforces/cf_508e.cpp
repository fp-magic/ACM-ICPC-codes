#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[5][5],sum[5][5],mid[5][5],f[5][5];
/*
首先每个砖头相当于一个c1<->c2的边权为v的无向边，则要求的是一个最大权值和路径
做法是枚举24种前四位路径，如1-2-3-4，1-2-4-3，在每个点用addstaydis把走到另
一个点又走回来的答案加上（不含到下一个点），再addgodis走到在下一个点。走到第
四个点addstaydis后各个边最多剩余1个，暴力搜索一下即可。
做的远不如标称简洁，标称的想法枚举的与我不同，枚举的是走的路径，共2^16种，如
1-2-3-4-2-1-3-2。。。两个点之间最多addgodis来回走一次。
*/
int addstaydis(int c1,int c2)
{
    int s=0;
    if(c1>c2)swap(c1,c2);
    if(f[c1][c2]==0)return 0;
    if(f[c1][c2]==1&&c1!=c2)return 0;
    if(f[c1][c2]&1)
    {
        if(c1==c2)
        {
            s+=sum[c1][c2];
            f[c1][c2]=0;
        }else
        {
            s+=sum[c1][c2]-mid[c1][c2];
            f[c1][c2]=1;
        }
    }else
    {
        f[c1][c2]=0;
        s+=sum[c1][c2];
    }
    return s;
}
int addgodis(int c1,int c2)
{
    int s=0;
    if(c1>c2)swap(c1,c2);
    if(f[c1][c2]==0)return 0;
    if(f[c1][c2]&1)
    {
        f[c1][c2]=0;
        s+=sum[c1][c2];
    }else
    {
        f[c1][c2]=1;
        s+=sum[c1][c2]-mid[c1][c2];
    }
    return s;
}
int dfs(int x)
{
    int s=0,c1,c2;
    for(int i=1;i<=4;i++)
    {
        c1=min(i,x);c2=max(i,x);
        if(f[c1][c2])
        {
            f[c1][c2]=0;
            s=max(s,mid[c1][c2]+dfs(i));
            f[c1][c2]=1;
        }
    }
    return s;
}
int main()
{
    int n,m,i,j,k,s,t,c1,v,c2,d1,d2,d3,d4,ans;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    memset(mid,127,sizeof(mid));
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&c1,&v,&c2);
        if(c1>c2)swap(c1,c2);
        num[c1][c2]++;
        sum[c1][c2]+=v;
        mid[c1][c2]=min(mid[c1][c2],v);
    }
    ans=0;
    //below emunerate every path
    for(d1=1;d1<=4;d1++)
        for(d2=1;d2<=4;d2++)
            for(d3=1;d3<=4;d3++)
                for(d4=1;d4<=4;d4++)
                    if(d1!=d2&&d1!=d3&&d1!=d4&&d2!=d3&&d2!=d4&&d3!=d4)
                    {
                        for(i=1;i<=4;i++)
                            for(j=1;j<=4;j++)
                                f[i][j]=num[i][j];
                        s=0;
                        for(i=1;i<=4;i++)
                            if(i!=d2)
                                s+=addstaydis(d1,i);
                        if(f[min(d1,d2)][max(d1,d2)]==0)
                        {
                            s+=dfs(d1);
                            ans=max(ans,s);
                            continue;
                        }else
                            s+=addgodis(d1,d2);
                        for(i=1;i<=4;i++)
                            if(i!=d3)
                                s+=addstaydis(d2,i);
                        if(f[min(d2,d3)][max(d2,d3)]==0)
                        {
                            s+=dfs(d2);
                            ans=max(ans,s);
                            continue;
                        }else
                            s+=addgodis(d2,d3);
                        for(i=1;i<=4;i++)
                            if(i!=d4)
                                s+=addstaydis(d3,i);
                        if(f[min(d3,d4)][max(d3,d4)]==0)
                        {
                            s+=dfs(d3);
                            ans=max(ans,s);
                            continue;
                        }else
                            s+=addgodis(d3,d4);
                        s+=addstaydis(d4,d4);
                        //dfs remain paths
                        s+=dfs(d4);
                        ans=max(ans,s);
                    }
    printf("%d\n",ans);
    return 0;
}