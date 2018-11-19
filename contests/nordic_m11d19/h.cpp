#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string nm;
vector<string>sans;
char ch;
int main()
{
    int n,m,i,j,s,p,c,t,r,tt,pans,flag,tmp;
    long long k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        pans=-1;sans.clear();
        for(i=1;i<=m;i++)
        {
            nm="";
            do
            {
                ch=getchar();
                if(ch==',')break;
                nm+=ch;
            }while(ch!=',');
            scanf("%d,%d,%d,%d",&p,&c,&t,&r);
            getchar();
            if((long long)10080*(long long)c*(long long)t>=(long long)n*(t+r))
            {
                if(pans==-1||p<pans)
                {
                    pans=p;
                    sans.clear();
                    sans.push_back(nm);
                }else
                if(p==pans)
                    sans.push_back(nm);
            }
        }
        if(sans.size()==0)printf("no such mower\n");
        for(i=0;i<sans.size();i++)
            printf("%s\n",sans[i].c_str());
    }
    return 0;
}