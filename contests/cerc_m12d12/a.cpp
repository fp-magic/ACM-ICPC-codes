#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
#define mp make_pair
#define rep(i, a, b) for(int i = (a);i < (b);++i)
typedef long long LL;
int N, M, S[maxn][maxn];
char A[maxn][maxn];
bool G[maxn][maxn];

void init()
{
	scanf("%d%d", &N, &M);
	rep(i, 0, N)
		fgets(A[i], maxn, stdin);
	rep(i, 0, N) puts(A[i]);
}

void work()
{

}

int main()
{
	while(~scanf("%d%d", &N, &M))
	{
		init();
		work();
	}
	return 0;
}

