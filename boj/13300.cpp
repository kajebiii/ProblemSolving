#include <stdio.h>
#include <algorithm>

using namespace std;

int Cnt[7][2];
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) {
		int s, g;
		scanf("%d%d", &s, &g);
		Cnt[g][s]++;
	}
	int ans = 0;
	for(int j=0; j<2; j++) for(int i=1; i<=6; i++)
		ans += (Cnt[i][j] + K-1) / K;
	printf("%d", ans);
	return 0;
}


