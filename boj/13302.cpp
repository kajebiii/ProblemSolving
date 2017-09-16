#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10, INF = 0x7fffffff;

int N, M, Chk[MAX_N];
int Dy[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &N, &M);
	for(int i=0, x; i<M; i++) scanf("%d", &x), Chk[x] = 1;
	for(int i=0; i<=N+5; i++) for(int j=0; j<=N; j++) Dy[i][j] = INF;
	Dy[0][0] = 0;
	for(int i=1; i<=N; i++) {
		if(Chk[i] == 1)
			for(int j=0; j<=N; j++)
				Dy[i][j] = min(Dy[i][j], Dy[i-1][j]);
		for(int j=0; j<=N; j++) {
			if(Dy[i-1][j] == INF) continue;
			if(j >= 3) Dy[i][j-3] = min(Dy[i][j-3], Dy[i-1][j]);
			Dy[i][j] = min(Dy[i][j], Dy[i-1][j] + 10000);
			Dy[i+2][j+1] = min(Dy[i+2][j+1], Dy[i-1][j] + 25000);
			Dy[i+4][j+2] = min(Dy[i+4][j+2], Dy[i-1][j] + 37000);
		}
	}
	int ans = INF;
	for(int i=N; i<=N+5; i++) for(int j=0; j<=N; j++)
		ans = min(ans, Dy[i][j]);
	printf("%d\n", ans);
	return 0;
}