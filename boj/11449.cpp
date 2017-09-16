#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 100;

int N, Nr[MAX_N][2], Val[MAX_N];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);
		for(int i=0; i<N; i++) Val[i] = Nr[i][0] - Nr[i][1];
		for(int i=1; i<N; i++) Val[i] = Val[i-1] + Val[i];
		if(Val[N-1] < 0) puts("IMPOSSIBLE");
		else {
			int ix = -1, minV = 0x7fffffff;
			for(int i=0; i<N; i++) if(minV > Val[i]) minV = Val[i], ix = i;
			ix = (ix + 1) % N;
			printf("%d\n", ix+1);
		}
	}
	return 0;
}