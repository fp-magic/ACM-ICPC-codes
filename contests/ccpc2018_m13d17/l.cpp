#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define sqr(s) ((s) * (s))
const int inf = 0x7fffffff / 3.27;
const int maxn = 1000005;
ll i, j, t, n, m, l, r, k, z, y, x;
const int S=20;//随机算法判定次数，S越大，判错概率越小


//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
    a%=c;
    b%=c;
    long long ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    long long tmp=x;
    long long ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}





//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
    long long ret=pow_mod(a,x,n);
    long long last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;

bool primeq(long long n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    long long x=n-1;
    long long t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}

ll pr[maxn], psz;
bool vis[maxn];
void get_prime()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i]) pr[psz++] = i;
        for (j = 0; j < maxn; j++)
        {
            if (pr[j] * i >= maxn) break;
            vis[pr[j] * i] = true;
            if (i % pr[j] == 0) break;
        }
    }
}
int calc(ll s)
{
    int i;
    for (i = 0; i < psz; i++)
    {
        if (primeq(s - pr[i]))
        {
            printf("%lld %lld ", pr[i], s - pr[i]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int I, T = 1;
    scanf("%d", &T);
    get_prime();
    for (I = 1; I <= T; I++)
    {
        scanf("%I64d", &n);
        printf("Case %d: ",I);
        if (n < 12)
            printf("IMPOSSIBLE\n");
        else
        {
            ll num;
            for( num=n-10;;num--)
            {
                if(primeq(num)){
                    break;
                }
            }
            if(calc(n - 6-num)){
                printf("2 2 2 %I64d\n",num);
            }else{
                for( num=n-11;;num--)
                {
                    if(primeq(num)){
                        break;
                    }
                    
                }
                calc(n - 7-num);
                printf("2 2 3 %I64d\n",num);
            }
        }
    }
    return 0;
}