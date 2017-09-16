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
		Cnt[(g+1)/2][s]++;
	}
	int ans = 0;
	ans += (Cnt[1][0] + Cnt[1][1] + K-1) / K;
	for(int j=0; j<2; j++) for(int i=2; i<=3; i++)
		ans += (Cnt[i][j] + K-1) / K;
	printf("%d", ans);
	return 0;
}


