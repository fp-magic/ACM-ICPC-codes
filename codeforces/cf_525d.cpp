#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int ask(int x,int y)
{
    printf("? %d %d\n",x,y);
    int tmp;
    fflush(stdout);
    scanf("%d",&tmp);
    return tmp;
}
int main()
{
    int swap,n,m,x,y,d,i,j,k,s,t,tt;
    int a=0,b=0;
    swap=ask(0,0);
    s=0;t=0;
    for(i=29;i>=0;i--)
    {
        if(swap==-1)
        {
            x=ask(s,t+(1<<i));
            y=ask(s+(1<<i),t);
            if(x==1&&y==-1)
            {
                s+=1<<i;
                t+=1<<i;
                swap=-1;
            }else
            if(x==1&&y==1)
            {
                t+=1<<i;
                swap=1;
            }else
            if(x==-1&&y==-1)
            {
                t+=1<<i;
                swap=-1;
            }else
            if(x==-1&&y==1)
            {
                swap=-1;
            }else
            {
                t+=1<<i;
                swap=0;
            }
        }else
        if(swap==1)
        {
            x=ask(s,t+(1<<i));
            y=ask(s+(1<<i),t);
            if(x==1&&y==-1)
            {
                s+=1<<i;
                t+=1<<i;
                swap=1;
            }else
            if(x==-1&&y==-1)
            {
                s+=1<<i;
                swap=-1;
            }else
            if(x==1&&y==1)
            {
                s+=1<<i;
                swap=1;
            }else
            if(x==-1&&y==1)
            {
                swap=1;
            }else
            {
                s+=1<<i;
                swap=0;
            }
        }else
        {
            x=ask(s,t+(1<<i));
            if(x==1)
            {
                s+=1<<i;
                t+=1<<i;
                swap=0;
            }else
            {
                swap=0;
            }
        }
    }
    printf("! %d %d\n",s,t);
    fflush(stdout);
    return 0;
}