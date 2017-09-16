#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10, MAX_C = 1e4 + 10, MOD = 1e9 + 7;

int N, C, Dy[MAX_N][MAX_C], Sum[MAX_N][MAX_C];

int main()
{
	scanf("%d%d", &N, &C);
	Dy[1][0] = 1;
	for(int i=2; i<=N; i++)
	{
		for(int j=0; j<=C; j++) Sum[i-1][j] = ( (j>0 ? Sum[i-1][j-1]:0) + Dy[i-1][j] ) % MOD;
		for(int j=0; j<=C; j++)
			Dy[i][j] = (Sum[i-1][j] - (j >= i ? Sum[i-1][j-i] : 0) + MOD) % MOD;
	}
	printf("%d\n", Dy[N][C]);
	return 0;
}