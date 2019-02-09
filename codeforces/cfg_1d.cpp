#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
using namespace std;

const int N=1000010;
int n,m,x,s[N],f[N][3][3];

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&x),s[x]++;
	memset(f,-1,sizeof(f)); f[0][0][0]=0;
	rep(i,0,m-1) rep(j,0,2) rep(k,0,2) if (~f[i][j][k] && j+k<=s[i+1])
		rep(l,0,min(2,s[i+1]-j-k))
			f[i+1][k][l]=max(f[i+1][k][l],f[i][j][k]+l+(s[i+1]-j-k-l)/3);
	printf("%d\n",f[m][0][0]);
	return 0;
}