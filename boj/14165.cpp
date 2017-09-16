#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <assert.h>

using namespace std;

const int MAX_N = 1e3 + 5, MAX_K = 10 + 1, MOD = 1e9 + 9;

int N, M, K, A[MAX_N], B[MAX_N], C[MAX_N][MAX_K];
int Cnt[MAX_N][MAX_N][MAX_K], Sum[MAX_N][MAX_N][MAX_K];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%d", &A[i]); sort(A+1, A+N+1);
	for(int i=1; i<=M; i++) scanf("%d", &B[i]); sort(B+1, B+M+1);
	for(int i=0, j; i<=max(N, M); i++) for(C[i][0] = 1, j=1; j<=min(i, K); j++) 
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	Cnt[N][M][K] = 1;
	int ans = 0;
	for(int k=K; k>=1; k--) for(int i=N; i>=1; i--) for(int j=M; j>=1; j--) {
		Sum[i][j][k] = (1ll * Sum[i+1][j][k] + Sum[i][j+1][k] - Sum[i+1][j+1][k] + Cnt[i][j][k]) % MOD;
		if(A[i] > B[j]) Cnt[i-1][j-1][k-1] = (Cnt[i-1][j-1][k-1] + Sum[i][j][k]) % MOD;
	}
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) ans = (ans + Cnt[i][j][0]) % MOD;
	printf("%d\n", ans);
	return 0;
}