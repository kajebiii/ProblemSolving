#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e2 + 10;

int N[2], Nr[2][MAX_N];
int Dy[MAX_N][MAX_N], P[MAX_N][MAX_N][2];
int Memo[MAX_N], Ix[MAX_N];

void print(int x, int y)
{
	if(x == 0) return;
	print(P[x][y][0], P[x][y][1]);
	printf("%d ", Nr[0][x]);
}

int main()
{
	for(int k=0; k<2; k++)
	{
		scanf("%d", &N[k]);
		for(int i=1; i<=N[k]; i++) scanf("%d", &Nr[k][i]);
	}

	Dy[0][0] = 1;
	Memo[0] = 1;
	int ans = 0, ansIx[2] = {0, 0};
	for(int i=1; i<=N[0]; i++) for(int j=N[1]; j>=1; j--)
	{
		if(Nr[0][i] != Nr[1][j]) continue;
		int now = 1, ix = 0;
		for(int k=1; k<j; k++) 
		{
			if(Nr[1][k] >= Nr[1][j]) continue;
			now = max(now, Memo[k]);
			if(now == Memo[k]) ix = k;
		}
		P[i][j][0] = Ix[ix], P[i][j][1] = ix;
		Memo[j] = max(Memo[j], Dy[i][j] = now + 1);
		if(Memo[j] == Dy[i][j]) Ix[j] = i;
		ans = max(ans, now);
		if(ans == now) { ansIx[0] = i, ansIx[1] = j; }
	}
	printf("%d\n", ans);
	print(ansIx[0], ansIx[1]);
	return 0;
}