#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
#define mp make_pair
#define rep(i, a, b) for(int i = (a);i < (b);++i)
typedef long long LL;
int N, M, S[maxn][maxn];
char A[maxn][maxn], B[maxn][maxn];

inline int getC()
{
	int ch;
	while((ch = getchar()) > 126 || ch < 33);
	return ch;
}

void init()
{
	rep(i, 0, N) rep(j, 0, M) A[i][j] = getC();
}

int calc(char A[][maxn], int N, int M)
{
	rep(j, 0, M) S[0][j] = 1;
	int ans = 0;
	//rep(i, 0, N) rep(j, 0, M) printf("%c%c", A[i][j], " \n"[j+1 == M]);
	rep(i, 1, N)
	{
		rep(j, 0, M) S[i][j] = (A[i][j] == A[i-1][j]) ? S[i-1][j] + 1 : 1;
		//rep(j, 0, M) printf("%d%c", S[i][j], " \n"[j+1 == M]);
		int mx = 1;
		rep(j, 1, M)
		{
			if(A[i][j] == A[i][j-1]) mx = min(mx + 1, S[i][j]);
			else mx = 1;
			ans += mx - 1;
		}
	}
	return ans;
}

void work()
{
	int ans = 0;
	ans += calc(A, N, M);
	rep(i, 0, M) rep(j, 0, N) B[i][j] = A[j][M-1-i];
	ans += calc(B, M, N);
	rep(i, 0, N) rep(j, 0, M) A[i][j] = B[j][N-1-i];
	ans += calc(A, N, M);
	rep(i, 0, M) rep(j, 0, N) B[i][j] = A[j][M-1-i];
	ans += calc(B, M, N);
	rep(i, 0, N) rep(j, 0, M) A[i][j] = B[j][N-1-i];
	printf("%d\n", ans);
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

