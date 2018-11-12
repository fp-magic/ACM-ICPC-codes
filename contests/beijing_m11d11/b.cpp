#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int b[205];
vector<long long>ans;
int main()
{ freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    int n,m,i,j,k,t,tot=1,ntot=1,flag=0,num=0,pre=0;
    char ch;
    long long s;
    t=0;s=0;ans.clear();
    memset(b,0,sizeof(b));
    while(scanf("%c",&ch)!=EOF)
    {
        //flag=0 ready for inputing number
        //flag=1 cannot input number
        //flag=2 inputing number
        //s the number
        //printf("(%d-",flag);
        if(ch<='z'&&ch>='a')
        {
            pre=2;
            num++;
            if(flag==2)
            {
                if(num!=1)b[ntot]--;
                else ans.push_back(s);
            }
            flag=1,s=0;
        }
        else
        if(ch<='9'&&ch>='0')
        {
            pre=1;
            num++;
            if(flag==0)
            {
                s=(long long)(ch-'0'),ntot=tot,b[ntot]++,flag=2;
            }else
            if(flag==2)
            {
                if(s==0){flag=3;b[ntot]--;}
                else s=s*10+(long long)(ch-'0');
            }
        }else
        if(ch==' ')
        {
            pre=0;
            num++;
            if(flag==2)ans.push_back(s),s=0,flag=0;
            else if(flag==1)flag=0,s=0;
            else if(flag==0)s=0;
            else if(flag==3)flag=0,s=0;
        }else
        {//printf("(%d)",pre);
            tot++;num=0;
            if(flag==1&&pre!=1)flag=0,s=0;
        }
        //printf("%lld-%d)",s,flag);
    }
    if(num==0)tot--;
    if(flag==2){ans.push_back(s);}
    if(ans.size()>0)
    for(i=0;i<ans.size()-1;i++)
    {
        printf("%lld ",ans[i]);
    }
    if(ans.size()>0)printf("%lld\n",ans[ans.size()-1]);
    else printf("\n");
    for(i=1;i<=tot;i++)printf("%d\n",b[i]);
    return 0;
}