#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
int main(){
	int n,i;
    scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)scanf("%d",&b[i]);
	for(i=n;i;--i)a[i]-=a[i-1],b[i]-=b[i-1];
	sort(a+2,a+n+1);
	sort(b+2,b+n+1);
	for(i=1;i<=n;++i)
		if(a[i]!=b[i])return puts("No"),0;
	puts("Yes");
	return 0;
}