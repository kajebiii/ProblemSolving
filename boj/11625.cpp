#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 100;

int N, K, L, Nr[MAX_N];
int main() {
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d%d%d", &L, &N, &K);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

		int res = -1;
		for(int l=1, r=L; l<=r;) {
			int m = (l + r) >> 1;
			int last = 0, cnt = 0;
			for(int i=1; i<=N; i++) {
				int diff = Nr[i] - last;
				if(diff <= 0) continue;
				if(diff > m) { cnt += 2; last = Nr[i]-1 + m; } else { cnt++; last += m; }
			}
			if(L - last > 0) cnt++;
			if(cnt <= K) res = m, r = m-1; else l = m+1;
		}
		printf("%d\n", res);
	}
	return 0;
}