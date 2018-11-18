#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[3][105][105][105][2];//左脚步数 一阶步数 左脚一阶步数 
long long sum[105];
void fordebug(int i,int j,int k,int ii)
{
    int zuo1,zuo2,you1,you2;
    zuo1=ii;you1=k-ii;
    zuo2=j-ii;you2=(i-k-(j-ii)*2)/2;
    if(i<=6)printf("(%d %d %d %d %d)\n",i,zuo1,you1,zuo2,you2);
}
int main()
{
    int n,m,i,j,k,s,t,tt,ii,zuo1,zuo2,you1,you2,nowdir;
    scanf("%d",&tt);
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    a[0][0][0][0][1]=1;
    sum[0]=1;
    for(i=1;i<=100;i++)
    {
        for(j=i;j>=0;j--)
            for(k=i;k>=0;k-=2)
                for(ii=k;ii>=0;ii--)
                {
                    t=i%3;
                    zuo1=ii;you1=k-ii;
                    zuo2=j-ii;you2=(i-k-(j-ii)*2)/2;
                    if(zuo1<0||you1<0||zuo2<0||you2<0)continue;
                    if(zuo1+zuo2==you1+you2+1)
                    {//if(i<=6)printf("%d %d %d %d %d\n",i,zuo1,you1,zuo2,you2);
                        if(zuo1>0)
                        {
                            a[t][j][k][ii][0]+=a[(t+2)%3][j-1][k-1][ii-1][1];
                            //if(i<=6)printf("=%lld",a[(t+2)%3][j-1][k-1][ii-1][1]),fordebug(i-1,j-1,k-1,ii-1);
                            if(zuo1==you1&&zuo2==you2&&(zuo1+you1<=zuo2+you2))
                                sum[i]+=a[(t+2)%3][j-1][k-1][ii-1][1];
                        }
                        if(zuo2>0)
                        {
                            a[t][j][k][ii][0]+=a[(t+1)%3][j-1][k][ii][1];
                            //if(i<=6)printf("+%lld",a[(t+1)%3][j-1][k][ii][1]),fordebug(i-2,j-1,k,ii);
                            if(zuo1==you1&&zuo2==you2&&(zuo1+you1<=zuo2+you2))
                                sum[i]+=a[(t+1)%3][j-1][k][ii][1];
                        }
                    }
                    if(zuo1+zuo2==you1+you2)
                    {//if(i<=6)printf("%d %d %d %d %d\n",i,zuo1,you1,zuo2,you2);
                        if(you1>0)
                        {
                            a[t][j][k][ii][1]+=a[(t+2)%3][j][k-1][ii][0];
                            if(zuo1==you1&&zuo2==you2&&(zuo1+you1<=zuo2+you2))
                                sum[i]+=a[(t+2)%3][j][k-1][ii][0];
                        }
                        if(you2>0)
                        {
                            a[t][j][k][ii][1]+=a[(t+1)%3][j][k][ii][0];
                            if(zuo1==you1&&zuo2==you2&&(zuo1+you1<=zuo2+you2))
                                sum[i]+=a[(t+1)%3][j][k][ii][0];
                        }
                    }
                }
    }
    while(tt--)
    {
        scanf("%d%d",&s,&t);
        printf("%d %lld\n",s,sum[t]);
    }
    return 0;
}