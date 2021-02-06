#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
const long long n=10;
const long long m=1000000;
int a[n];
void cnt(){
    for(int i=0;i<n;++i)a[i]=i;
    for(int i=0;i<m-1;i++){
        next_permutation(a,a+n);
    }
    for(int j=0;j<n;++j)printf("%d",a[j]);
    printf("\n");
}
bool f[100005];
void ans(){
}
int main(){
    long long m,i,j,k,s,t;
    cnt();
    ans();
    return 0;
}