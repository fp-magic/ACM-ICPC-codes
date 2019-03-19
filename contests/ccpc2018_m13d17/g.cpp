#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
const _int128 mod=1e9+7;
_int128 cnt(_int128 x){
    return (((x*(x+1ll)/2ll*x*(x+1ll)/2ll+x*(x+1ll))/3ll-x*(x+1ll)*(x*2ll+1ll)/6ll)/2ll)%mod;
}
void print(__int128 x)  
{  
    if(!x)  
    {  
        puts("0");  
        return ;  
    }  
    string ret="";  
    while(x)  
    {  
        ret+=x%10+'0';  
        x/=10;  
    }  
    reverse(ret.begin(),ret.end());  
    cout<<ret<<endl;  
}
int main(){
    unsigned long long n,m,i,j,k,s,t,tt,step=0;
    scanf("%lld",&tt);
    while(tt--){
        scanf("%lld%lld",&n,&m);
        printf("Case %lld: ",++step);
        print(cnt(n)*cnt(m)%mod);
    }
    return 0;
}