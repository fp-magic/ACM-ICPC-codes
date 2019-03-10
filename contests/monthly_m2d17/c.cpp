#include<bits/stdc++.h>
using namespace std;
#define rep(i,st,en) for(i=st;i<=en;i++)
#define pb push_back
#define fr first 
#define sc second 
typedef long long ll;
typedef long double ld;
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    inline void readll(long long int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
vector<pair<ll,int> >a[1000005];
int mod=999983;
int main()
{
    int tt,n,m,q,i,j,flag;
    ll k,s,t;
    scanf("%d",&tt);
    while(tt--)
    {
        fastIO::read(n);
        //printf("%d!\n",n);
        fastIO::read(q);
        for(i=0;i<mod;i++)a[i].clear();
        for(i=1;i<=n;i++)
        {//printf("=%d\n",i);
            flag=false;
            fastIO::readll(k);
            s=k%mod;
            for(j=0;j<a[s].size();j++)
                if(a[s][j].fr==k)
                {
                    flag=true;
                    a[s][j].sc++;
                    break;
                }
            if(!flag)
            {
                a[s].pb(make_pair(k,1));
            }
        }//puts(">");
        for(i=1;i<=q;i++)
        {
            flag=false;
            fastIO::readll(k);
            s=k%mod;
            for(j=0;j<a[s].size();j++)
                if(a[s][j].fr==k)
                {
                    flag=true;
                    printf("%d\n",a[s][j].sc);
                    break;
                }
            if(!flag)
            {
                printf("0\n");
            }
        }
    }
    return 0;
}