#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<int,int>mp,np;
int cnt;
char a[1005];
int d[1005];
int l[1005],r[1005],p[1005];
int main()
{
    int root,i,j,k,s,t,n;
    scanf("%d",&n);
    memset(p,255,sizeof(p));
    memset(d,255,sizeof(d));
    memset(l,255,sizeof(l));
    memset(r,255,sizeof(r));
    mp.clear();np.clear();
    cnt=0;
    scanf("%d",&k);np[cnt]=k;mp[k]=cnt++;
    k=mp[k];
    d[k]=1;root=k;n--;
    while(n--)
    {
        scanf("%d",&k);
        np[cnt]=k;
        mp[k]=cnt++;
        k=mp[k];
        s=root;
        do{
            if(np[k]<np[s])
            {
                if(l[s]==-1)
                {
                    l[s]=k;
                    d[k]=d[s]+1;
                    p[k]=s;
                    break;
                }else
                    s=l[s];
            }else{
                if(r[s]==-1)
                {
                    r[s]=k;
                    d[k]=d[s]+1;
                    p[k]=s;
                    break;
                }else
                    s=r[s];
            }
        }while(1);
    }
    //for(i=0;i<=4;i++)printf("%d: d%d p%d l%d r%d\n",i,d[i],p[i],l[i],r[i]);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&s);
        scanf("%s",a);
        if(a[0]=='i')
        {
            scanf("%s",a);
            scanf("%s",a);
            if(a[0]=='r'&&a[1]=='o')
            {//puts("1");
                s=mp[s];
                if(s==root)printf("Yes\n");else printf("No\n");
            }else
            if(a[0]=='p')
            {
                scanf("%s%d",a,&t);//puts("2");
                s=mp[s];t=mp[t];
                if(p[t]==s)printf("Yes\n");else printf("No\n");
            }else
            if(a[0]=='l')
            {
                scanf("%s",a);
                scanf("%s%d",a,&t);//puts("3");
                s=mp[s];t=mp[t];
                if(l[t]==s)printf("Yes\n");else printf("No\n");
            }else
            if(a[0]=='r')
            {
                scanf("%s",a);
                scanf("%s%d",a,&t);//puts("4");
                s=mp[s];t=mp[t];
                if(r[t]==s)printf("Yes\n");else printf("No\n");
            }
        }else
        {
            scanf("%d",&t);
            scanf("%s",a);
            scanf("%s",a);
            if(a[0]=='s')
            {//puts("5");
                s=mp[s];t=mp[t];
                if(s!=t&&p[s]==p[t])printf("Yes\n");else printf("No\n");
            }else
            {
                scanf("%s",a);scanf("%s",a);scanf("%s",a);//puts("6");
                s=mp[s];t=mp[t];
                if(d[s]==d[t])printf("Yes\n");else printf("No\n");
            }
        }
    }
    return 0;
}