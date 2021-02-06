#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
long long a[1000005];
vector<int> abun;
long long n=28123;
void cnt(){
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;++i){
        int t=(int)sqrt(i);
        for(int j=1;j<=t;++j){
            if(j<i&&i%j==0){
                a[i]+=j+i/j;
            }
        }
        if(t*t==i&&t<i)a[i]-=t;
        a[i]-=i;
        if(a[i]>i)abun.push_back(i);
    }
    printf("%d\n",abun.size());
}
bool f[100005];
void ans(){
    memset(f,0,sizeof(f));
    for(int i=0;i<abun.size();++i)
    for(int j=0;j<=i;++j){
        f[abun[i]+abun[j]]=true;
    }
    long long s=0,t=0;
    for(int i=0;i<=n;++i)if(!f[i]){
        //printf("%d\n",i);
        t++;
        s+=i;
    }
    printf("%lld %lld\n",s,t);
}
int main(){
    long long m,i,j,k,s,t;
    cnt();
    for(i=1;i<=20;i++)printf("%lld %d\n",i,a[i]);
    for(i=1;i<=20;i++)printf("%lld %d\n",i,abun[i]);
    ans();
    return 0;
}