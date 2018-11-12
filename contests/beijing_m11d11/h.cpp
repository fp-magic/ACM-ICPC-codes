#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2000;
long long f[45][2000];
char ch[2000];
int n,m;
struct trie
{
    int next[maxn][2], fail[maxn], end[maxn];
    int root, cnt;
    int new_node()
    {
        memset(next[cnt], -1, sizeof next[cnt]);
        end[cnt++] = 0;
        return cnt - 1;
    }
    void init()
    {
        cnt = 0;
        root = new_node();
    }
    void insert(char *buf)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            int id = buf[i] - '0';
            if (next[now][id] == -1)
            {
                next[now][id] = new_node();
            }
            now = next[now][id];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < 2; i++)
        {
            if (next[root][i] == -1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 2; i++)
            {
                if (next[now][i] == -1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        }
    }
    long long solve()
    {
        f[0][0]=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<cnt;j++)
                for(int k=0;k<2;k++)
                {
                    if(!end[next[j][k]])
                        f[i+1][next[j][k]]+=f[i][j];
                }
        long long ans=0;
        for(int i=0;i<cnt;i++)
            ans+=f[m][i];
        return ans;
    }
} ac;
long long pw[45];
int main()
{
    int i,j,k,tt;
    long long s,t;
    pw[0]=1;for(i=1;i<45;i++)pw[i]=pw[i-1]*2;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",ch);
        ac.init();
        ac.insert(ch);
        for(i=0;i<n;i++)
        {
            if(ch[i]=='1')ch[i]='0';else ch[i]='1';
            ac.insert(ch);
            if(ch[i]=='1')ch[i]='0';else ch[i]='1';
        }
        ac.build();
        memset(f,0,sizeof(f));
        printf("%lld\n",pw[m]-ac.solve());
    } 
    return 0;
}