#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 1e2 + 10;
typedef long long ll;

int K, N, V, Nr[MAX_N];

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d%d", &K, &N, &V);
		for(int i=0; i<N; i++) scanf("%d", &Nr[i]); Nr[N++] = V+1;
		sort(Nr, Nr+N);
		
		ll now = 0; int ans = 0;
		for(int i=0; i<N; i++) {
			while(now < Nr[i] - 1) {
				now += (now + 1) * K;
				ans++;
			}
			now += 1ll * Nr[i] * K;
		}

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}