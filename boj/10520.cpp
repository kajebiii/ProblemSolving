#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 100, INF = 0x7fffffff;

int N, D, Dy[MAX_N][25], Nr[MAX_N], Sum[MAX_N];

int near(int v)
{
	return (v+5)/10 * 10;
}
int main()
{
	scanf("%d%d", &N, &D); D++;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]), Sum[i] = Sum[i-1] + Nr[i];
	for(int i=1; i<=N; i++) for(int d=0; d<=D; d++) Dy[i][d] = INF;
	Dy[0][0] = 0;
	for(int i=1; i<=N; i++) for(int j=1; j<=D; j++) for(int k=1; k<=i; k++)
		if(Dy[k-1][j-1] != INF)
			Dy[i][j] = min(Dy[i][j], Dy[k-1][j-1] + near(Sum[i] - Sum[k-1]));
	int ans = INF;
	for(int i=1; i<=D; i++) ans = min(ans, Dy[N][i]);
	printf("%d\n", ans);
	return 0;
}