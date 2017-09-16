#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 100, MAX_K = 1e2 + 10, MOD = 1e9 + 7;

int K, N, F[MAX_N], Nr[MAX_N], Dy[MAX_N];


int main() {
	scanf("%d%d", &K, &N);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=2, ix=0; i<=N; i++) {
		while(ix && Nr[ix+1] != Nr[i]) ix = F[ix];
		if(Nr[ix+1] == Nr[i]) ix++;
		F[i] = ix;
	}
	Dy[0] = 0;
	int pow = K;
	for(int i=1; i<=N; i++) {
		Dy[i] = (Dy[F[i]] + pow) % MOD;
		pow = (1ll * pow * K) % MOD;
		printf("%d\n", Dy[i]);
	}
	return 0;
}