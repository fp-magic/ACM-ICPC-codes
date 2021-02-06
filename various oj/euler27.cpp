#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
const long long n=10;
const long long m=1000000;
int a[1000000];
int nxt[1000000];
bool is_prime(int x){
    int t=min((int)sqrt(x),x-1);
    for(int i=2;i<=t;++i){
        if(x%i==0)return false;
    }
    return true;
}
void cnt(){
    int s=0;
    for(int i=-1000;i<=1000;++i)
    for(int j=-1000;j<=1000;++j){
        int k=0;
        while(true){
            if(k*k+i*k+j<=0)break;
            if(!is_prime(k*k+i*k+j))break;
            ++k;
        }if(i==1&&j==41)printf("%d\n",k);
        if(k>s){
            printf("%d %d %d %d\n",i,j, k,i*j);
            s=k;
        }
    }
}
void ans(){
}
int main(){
    long long m,i,j,k,s,t;
    cnt();
    ans();
    return 0;
}