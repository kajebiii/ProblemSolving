#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 7e1 + 5, MOD = 1000007;

int N, M, C, G[MAX_N][2], Ans[MAX_N];
int Dy[MAX_N][MAX_N][MAX_N][MAX_N]; //cnt, last, n, m;

int main()
{
	scanf("%d%d%d", &N, &M, &C);
	for(int i=1; i<=C; i++) scanf("%d%d", &G[i][0], &G[i][1]);
	int s_ix = -1;
	for(int i=1; i<=C; i++) if(G[i][0] == 1 && G[i][1] == 1) {s_ix = i;}
	if(s_ix == -1) Dy[0][0][1][1] = 1;
	else Dy[1][s_ix][1][1] = 1;

	for(int n=1; n<=N; n++) for(int m=1; m<=M; m++)
	{
		if(n == 1 && m == 1) continue;
		int ix = -1; for(int i=1; i<=C; i++) if(G[i][0] == n && G[i][1] == m) ix = i;

		for(int cnt=0; cnt<=C; cnt++)
		{
			if(ix == -1)
				for(int last=0; last<=C; last++)
				{
					Dy[cnt][last][n][m] += Dy[cnt][last][n-1][m];
					Dy[cnt][last][n][m] += Dy[cnt][last][n][m-1];
					Dy[cnt][last][n][m] %= MOD;
				}
			else if(ix != -1)
				for(int last=0; last<ix; last++)
				{
					Dy[cnt+1][ix][n][m] += Dy[cnt][last][n-1][m];
					Dy[cnt+1][ix][n][m] += Dy[cnt][last][n][m-1];
					Dy[cnt+1][ix][n][m] %= MOD;
				}
		}
	}
	for(int i=0; i<=C; i++) for(int j=0; j<=C; j++) Ans[i] += Dy[i][j][N][M], Ans[i] %= MOD;
	for(int i=0; i<=C; i++) printf("%d ", Ans[i]);
	return 0;
}