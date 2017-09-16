#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N];
int main() {
	if(0) {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);

		int ansA = 0, ansB = 0, maxV = 0;
		for(int i=2; i<=N; i++) {
			ansA += max(0, Nr[i-1] - Nr[i]);
			maxV = max(maxV, Nr[i-1] - Nr[i]);
		}
		for(int i=2; i<=N; i++)
			ansB += min(Nr[i-1], maxV);

		printf("Case #%d: ", tc);
		printf("%d %d\n", ansA, ansB);
	}
	return 0;
}