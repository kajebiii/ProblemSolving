#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

typedef long long ll;

const int MOD = 1e9 + 7, MAX_N = 1e3 + 100;

int Fact[MAX_N], Inv[MAX_N], H, W, N, Pow2[MAX_N * MAX_N];
int poww(int a, int b) {
	int res = 1, mul = a;
	while(b) {
		if(b % 2 == 1) res = 1ll * res * mul % MOD;
		mul = 1ll * mul * mul % MOD;
		b /= 2;
	}
	return res;
}
int ncr(int n, int r) {
	return 1ll * Fact[n] * Inv[r] % MOD * Inv[n-r] % MOD;
}

int solve(int n, int m) {
	int ans2 = 0;
	for(int i=1; i<=n; i++) for(int k=1; k<=n-i; k++) {
		int multi_l = poww((1 + poww(Pow2[k], MOD-2)), m) - 1;
		int multi_j = poww((1 + poww(Pow2[i], MOD-2)), m) - 1;
		ans2 += ((1ll * ncr(n, i) * ncr(n-i, k) % MOD) * Pow2[n*m] % MOD * (1ll * multi_l * multi_j % MOD) % MOD);
		ans2 %= MOD;
	}
//	printf("solve %d %d -> %d %d\n", n, m, ans, ans2);
	return ans2;
}
int dup(int n, int m) {
	int ans3 = 0;
	for(int i=1; i<=n; i++) for(int k=1; k<=n-i; k++) {
//		for(int j=1; j<=m; j++) {
			int p2k = (1 + poww(Pow2[k], MOD-2));
			int invIK = poww(1ll * Pow2[i] * p2k % MOD, MOD-2);
			int p2i = (1 + poww(Pow2[i], MOD-2));
//			ans3 += (1ll * ncr(n, i) * ncr(n-i, k) % MOD) * (1ll * ncr(m, j) % MOD) % MOD * Pow2[n*m-i*j] % MOD * (poww(p2k, m-j) - 1) % MOD;
			ans3 += (1ll * ncr(n, i) * ncr(n-i, k) % MOD) * Pow2[n*m] % MOD * 
				( (1ll * poww(p2k, m) * ( poww(1 + invIK, m) - 1) % MOD - poww(p2i, m) + 1 + MOD) % MOD) % MOD;
			ans3 %= MOD;
		}
//	printf("dup %d %d -> %d %d %d\n", n, m, ans, ans2, ans3);
	return ans3;
}
int main() {
	scanf("%d%d", &H, &W); N = max(H, W);
	Fact[0] = Inv[0] = Pow2[0] = 1;
	for(int i=1; i<=N; i++) Fact[i] = 1ll * Fact[i-1] * i % MOD;
	for(int i=1; i<=N; i++) Inv[i]  = 1ll * Inv[i-1] * poww(i, MOD-2) % MOD;
	for(int i=1; i<=N*N; i++) Pow2[i] = 1ll * Pow2[i-1] * 2 % MOD;
	printf("%lld\n", (1ll * solve(H, W) + solve(W, H) - dup(H, W) + MOD) % MOD * poww(poww(2, H*W), MOD-2) % MOD);
	return 0;
}