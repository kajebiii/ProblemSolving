#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 500, MAX_J = 250, INF = 0x7fffffff;

int Chk[MAX_N];
int Dy[MAX_N][MAX_J+1], N, M;
int main() {
	scanf("%d%d", &N, &M);
	while(M--) {
		int x; scanf("%d", &x);
		Chk[x] = 1;
	}

	Dy[1][0] = 1;
	for(int i=1; i<N; i++) {
		for(int j=0; j<=MAX_J; j++)
			if(Dy[i][j]) {
				for(int k=-1; k<=1; k++) {
					int nj = j+k;
					if(nj <= 0) continue;
					if(Chk[i+nj]) continue;
					Dy[i+nj][nj] = min(Dy[i+nj][nj]?Dy[i+nj][nj]:INF, Dy[i][j]+1);
				}
			}
	}
	int ans = INF;
	for(int j=0; j<=MAX_J; j++)
		if(Dy[N][j])
			ans = min(ans, Dy[N][j]);
	if(ans == INF) ans = 0;
	printf("%d\n", ans-1);
	return 0;
}