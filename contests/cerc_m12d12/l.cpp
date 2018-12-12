#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int tt,n,m,i,j,k,s,t;
    memset(a,0,sizeof(a));
    for(i=1;i<=100;i++)
        for(j=i+1;i*j*j<=1000000;j++)
            for(k=j+1;i*j*k<=1000000;k++)
                a[i*j*k]++;
    //for(i=1;i<=100;i++)printf("%d\n",a[i]);
    for(i=2;i<=1000000;i++)a[i]+=a[i-1];
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}