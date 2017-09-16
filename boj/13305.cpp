#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 100;

int N, Nr[MAX_N], D[MAX_N];
int main() {
	scanf("%d", &N);
	for(int i=1; i<N; i++) scanf("%d", &D[i]);
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	int minV = 0x7fffffff;
	long long ans = 0;
	for(int i=1; i<N; i++) {
		minV = min(minV, Nr[i]);
		ans += 1ll * minV * D[i];
	}
	printf("%lld\n", ans);
	return 0;
}