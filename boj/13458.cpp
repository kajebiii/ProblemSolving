#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100;

int N, Nr[MAX_N], B, C;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	scanf("%d%d", &B, &C);

	long long ans = 0;
	for(int i=0; i<N; i++) {
		int now = 1;
		Nr[i] -= B;
		Nr[i] = max(0, Nr[i]);
		now += (Nr[i] + C-1) / C;
		ans += now;
	}
	printf("%lld\n", ans);
	return 0;
}