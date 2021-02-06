#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;
string a[100005];
char b[10000005];
int main(){
    long long n,m,i,j,k,s,t;
    i=0;
    t=0;
    s=0;
    freopen("p022_names.txt","r",stdin);
    scanf("%s",b);
    //printf("%s\n",b);
    k=strlen(b);
    n=0;
    for(i=0;i<k-1;++i){
        if(b[i]=='\"'||b[i]==','){
            continue;
        }
        a[n]+=b[i];
        if(b[i+1]=='\"')++n;
    }
    printf("%s %s\n",a[0].c_str(),a[n-1].c_str());
    sort(a,a+n);
    printf("%s %s\n",a[0].c_str(),a[n-1].c_str());
    for(i=0;i<n;++i){
        t=0;
        for(j=0;j<a[i].length();++j)t+=a[i][j]-'A'+1;
        if(i==937){
            printf("938: %s %lld\n",a[i].c_str(),t*(i+1));
        }
        s+=t*(i+1);
    }
    printf("%lld\n",s);
    return 0;
}