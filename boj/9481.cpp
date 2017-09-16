#include <stdio.h>

typedef long long ll;

const int MOD = 1e9 + 7, MAX_N = 5e3 + 100;
int N, L, R, C[MAX_N][MAX_N], F[MAX_N];
int Dy[MAX_N][MAX_N];
int getCnt(int n, int l)
{
	if(n < l) return 0;
	if(l == 0 && n > 0) return 0;
	if(n == l) return 1;
	if(Dy[n][l] != 0) return Dy[n][l] - 1;
	ll result = getCnt(n-1, l-1);
	result += 1ll * (n-1) * getCnt(n-1, l) % MOD;
//	for(int i=1; i<=n; i++)
//		result += 1ll * C[n-1][i-1] * getCnt(i-1, l-1) % MOD * F[n-i] % MOD;
	Dy[n][l] = result % MOD + 1;
	return Dy[n][l] - 1;
}
int main()
{
	for(int i=0, j; i<=5000; i++) for(C[i][0] = 1, j=1; j<=i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	F[0] = 1; for(int i=1; i<=5000; i++)
		F[i] = 1ll * F[i-1] * i % MOD;
	while(scanf("%d%d%d", &N, &L, &R) == 3)
	{
		if(N + L + R == 0) break;
		ll ans = 0;
		for(int i=1; i<=N; i++)
			ans += 1ll * C[N-1][i-1] * getCnt(i-1, L-1) % MOD * getCnt(N-i, R-1) % MOD;
		printf("%lld\n", ans % MOD);
	}
	return 0;
}