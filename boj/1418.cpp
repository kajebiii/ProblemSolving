#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 100, MAX_K = 1e2 +10;

int N, K;
int Val[MAX_N];
int main() {
	scanf("%d%d", &N, &K);
	for(int i=1; i<=N; i++) Val[i] = i;
	for(int k=1; k<=K; k++) {
		if(Val[k] == 1) continue;
		for(int i=k; i<=N; i+=k)
			while(Val[i] % k == 0) Val[i] /= k;
	}
	int ans = 0;
	for(int i=1; i<=N; i++) if(Val[i] == 1) ans++;
	printf("%d\n", ans);
	return 0;
}