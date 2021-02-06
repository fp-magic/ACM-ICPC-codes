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
void cnt(){
    int t=0;
    for(int i=2;i<1000;++i){
        int s=1,j;
        for(int j=999999;j>=0;j--){
            if(s<i){
                a[j]=0;
            }else{
                a[j]=s/i;
                s%=i;
            }
            s*=10;
            if(s==0)break;
        }
        if(s!=0){
            if(i==62){
                //for(int j=0;j<=100;++j)printf("%d ",a[j]);
            }
            int k=0;
            memset(nxt,0,sizeof(nxt));
            for(int ii=2,j=0;ii<=999999;ii++) {
                while(j>0&&(j==999999||a[ii]!=a[j+1])) j=nxt[j];
                if(a[ii]==a[j+1]) j++;
                nxt[ii]=j;
            }
            if(500000-nxt[500000]>t){
                t=500000-nxt[500000];
                printf("%d %d\n",i,t);
            }
            //printf("%d: %d\n",i,500000-nxt[500000]);
            if(i==62){
               // printf("%d\n",nxt[500000]);
                //for(int j=0;j<=100;++j)printf("%d ",nxt[j]);
                //return;
            }
           // for(int j=0;j<=50;++j)printf("%d(%d) ",j,nxt[j]);
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