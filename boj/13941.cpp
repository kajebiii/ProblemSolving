#include <stdio.h>
#include <algorithm>
#include <assert.h>

using namespace std;

const int MAX_N = 21, INF = 0x7fffffff;

int N, K, C[MAX_N][MAX_N];
int Dy[1<<MAX_N], Cnt[1<<MAX_N], Fast[1<<MAX_N];
int getDy(int s) {
	if(Dy[s] != INF) return Dy[s];
	int &val = Dy[s];
	if(Cnt[s] <= K) return val = 0;
	for(int before=s, ns = (s-1)&s; before > 0; before = ns, ns = (ns-1)&ns) {
		int choose = before - ns;
		int i = Fast[choose];
		for(int before=s, ns = (s-1)&s; before > 0; before = ns, ns = (ns-1)&ns) {
			int j = Fast[before - ns];
			if(i == j) continue;
			val = min(val, getDy(s - choose) + C[i][j]);
		}
	}
	return val;
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &C[i][j]);
	for(int i=0; i<(1<<N); i++) Dy[i] = INF;
	for(int i=0; i<N; i++) for(int s=0; s<(1<<i); s++) Cnt[s+(1<<i)] = Cnt[s] + 1;
	for(int i=0; i<N; i++) Fast[1<<i] = i;
	printf("%d\n", getDy((1<<N) - 1));
	return 0;
}