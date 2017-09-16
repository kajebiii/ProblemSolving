#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5e3 + 10, MOD = 1e9;

int C[MAX_N*2][MAX_N];
int main()
{
	int N, K; scanf("%d%d", &N, &K);
	for(int i=0, j; i<=N+K-1; i++)
		for(C[i][0]=j=1; j<=min(i, K-1); j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	printf("%d", C[N+K-1][K-1]);
	return 0;
}