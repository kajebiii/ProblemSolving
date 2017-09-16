#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e2 + 10, MAX_K = 2e1 + 10, INF = 0x7fffffff;

int N, K, Nr[MAX_N];
int Dy[MAX_N][MAX_N][MAX_K];
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

	for(int i=1; i<=N; i++)
		for(int k=1; k<=K; k++)
			Dy[i][i][k] = 1 - (Nr[i] == k);
	for(int l=2; l<=N; l++) for(int i=1, j=l; j<=N; i++, j++)
	{
		for(int k=1; k<=K; k++) Dy[i][j][k] = INF;
		for(int k=1; k<=K; k++) for(int o=i; o<j; o++)
			Dy[i][j][k] = min(Dy[i][j][k], Dy[i][o][k] + Dy[o+1][j][k]);
		int nowMin = INF;
		for(int k=1; k<=K; k++)
			nowMin = min(nowMin, Dy[i][j][k]);
		for(int k=1; k<=K; k++)
			Dy[i][j][k] = min(Dy[i][j][k], nowMin + 1);
	}

	int ans = INF;
	for(int i=1; i<=K; i++) ans = min(ans, Dy[1][N][i]);
	printf("%d\n", ans);
	return 0;
}