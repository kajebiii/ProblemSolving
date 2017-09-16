#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 7e4 + 100;

int N, M, Nr[MAX_N], minV[MAX_N], maxV[MAX_N];
int main() {
	while(scanf("%d", &N) == 1) {
		if(N == 0) break;
		scanf("%d", &M);

		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		minV[0] = 0x7fffffff; maxV[N+1] = 0;
		for(int i=1; i<=N; i++) minV[i] = min(minV[i-1], Nr[i]);
		for(int i=N; i>=1; i--) maxV[i] = max(maxV[i+1], Nr[i]);
		int ans = 0;
		for(int i=1; i<=N; i++)
			ans = max(ans, M / minV[i] * (maxV[i+1] - minV[i]));
		printf("%d\n", ans);
	}
	return 0;
}