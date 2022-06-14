#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b) ; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
int mm;
int f[5005][10205];
vector<vi>C;
vi a,vit;
vi cand;
vi nxt[10205];
vi son;
void dfs(int u, int pre){
    //printf("%d\n",u);
    vit[u]=1;
    son[u]=1;
    for(auto v:C[u])if(v!=pre){
        dfs(v,u);
        son[u]+=son[v];
    }
    //cout<<"1"<<endl;
    for(auto i:cand){
        if(i>son[u]*2+105)break;
        //cout<<"="<<i<<endl;
        if(a[u]%i!=0){
            f[u][i]=i;
        }else{
            f[u][i]=0;
        }
        //cout<<u<<" "<<i<<" "<<f[u][i]<<endl;
        //cout<<"-"<<i<<endl;
        for(auto v:C[u])if(v!=pre){
            int s=son[u]*2+105;
            for(auto j:nxt[i]){
                if(j>son[v]*2+105)break;
                s=min(s,f[v][j]);
            }
            //cout<<u<<" "<<i<<endl;
            f[u][i]+=s;
            if(f[u][i]>son[u]*2+105){
                break;
            }
        }
    }
    //for(int i=last[u];i>=2;--i){
    //    printf("%d %d %d\n",u,i,f[u][i]);
    //}
    //printf("%d %d %d\n",u,pre,last[u]);
}

int main(){
    //cin.tie(0) -> sync_with_stdio(false);
    //cin.exceptions(cin.failbit);
    int n,m,i,j,k,s,t;
    memset(f,63,sizeof(f));
    scanf("%d",&n);
    mm=n*2+105;
    C.resize(n);
    a.resize(n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;++i){
        scanf("%d%d",&s,&t);
        s--;
        t--;
        C[s].push_back(t);
        C[t].push_back(s);
    }
    for(i=2;i<=5000*2+105;++i){
        bool skip=false;
        for(j=2;j<=100;j++){
            if(i%(j*j)==0){
                skip=true;
                break;
            }
        }
        if(!skip){
            s=i;
            for(j=2;j<=100;++j){
                while(s%j==0)s/=j;
            }
            if(s>100)skip=true;
        }
        if(!skip){
            cand.push_back(i);
        }
    }
    //printf("%d\n",cand.size());
    s=0;
    for(i=0;i<cand.size();++i){
        for(j=0;j<cand.size();++j){
            if(__gcd(cand[i],cand[j])>=2){
                nxt[cand[i]].push_back(cand[j]);
            }
        }
        s+=nxt[i].size();
    }
    vit.resize(n,0);
    son.resize(n,0);
    //printf("%d\n",s);
    dfs(0,-1);
    for(i=2;i<=2*n+105;++i){
        s=min(s,f[0][i]);
    }
    printf("%d\n",s);
    return 0;
}