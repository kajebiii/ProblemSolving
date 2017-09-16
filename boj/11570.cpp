#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff, MAX_N = 2e3 + 100;

int N, Nr[MAX_N], Dy[MAX_N][MAX_N];
int getDiff(int a, int b)
{
	if(a == 0 || b == 0) return 0;
	return abs(Nr[a] - Nr[b]);
}
int main()
{
	scanf("%d", &N); for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) Dy[i][j] = INF;
	Dy[0][0] = Dy[1][0] = Dy[0][1] = 0;
	for(int p=2; p<=N; p++)
	{
		for(int i=0; i<p-1; i++) Dy[i][p] = min(Dy[i][p], Dy[i][p-1] + getDiff(p, p-1));
		for(int i=0; i<p-1; i++) Dy[p][i] = min(Dy[p][i], Dy[p-1][i] + getDiff(p, p-1));
		for(int i=0; i<p-1; i++) Dy[p-1][p] = min(Dy[p-1][p], Dy[p-1][i] + getDiff(i, p));
		for(int i=0; i<p-1; i++) Dy[p][p-1] = min(Dy[p][p-1], Dy[i][p-1] + getDiff(i, p));
	}
	int ans = INF;
	for(int i=0; i<N; i++) ans = min(ans, min(Dy[i][N], Dy[N][i]));
	printf("%d\n", ans);
	return 0;
}