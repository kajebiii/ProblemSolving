#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100, MOD = 123456789;

int N, S, Dy[MAX_N][2];
int main() {
	scanf("%d%d", &N, &S);
	Dy[1][1] = 1;
	for(int i=2; i<=N; i++) {
		Dy[i][1] = Dy[i-1][1] + Dy[i-1][0]; Dy[i][1] %= MOD;
		Dy[i][0] = Dy[i][1] - (i>=S?Dy[i-S][1]:0); Dy[i][0] %= MOD;
		Dy[i][0] += MOD; Dy[i][0] %= MOD;
	}

	int ans = 0;
	if(N <= S) ans++; //only one on 1st;
	// choose 1st;
	for(int plus=2; plus<=min(N, 2*S); plus++) {
		int calc = S - abs(plus - (S+1));
		ans += (1ll * calc * Dy[N - plus + 1][1] % MOD);
		ans %= MOD;
	}
	// don't choose 1st;
	for(int plus=2; plus<=min(N, S); plus++) {
		int calc = plus - 1;
		ans += (1ll * calc * Dy[N - plus + 1][1] % MOD);
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}