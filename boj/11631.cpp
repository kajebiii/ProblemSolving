#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_W = 1e3 + 10;

int N, W, Nr[MAX_N][2];

int pos(int ix, int t) {
	int l = Nr[ix][1] - Nr[ix][0];
	t %= (l * 2);
	if(t >= l) return -1;
	return Nr[ix][0] + t;
}
int solve() {
	int t = 0, x = 0;
	int maxT = W * W * 5;
	while(t < maxT) {
		if(x == W) break;

		bool forward = false;
//		for(int i=0; i<N; i++) printf("%d : [%d is %d]\n", t, i, pos(i, t));
		for(int i=0; i<N; i++) if(pos(i, t) == x) {forward = true; break;}
		if(forward) x++; else x--;
		t++;
	}
	if(t >= maxT) return -1;
	assert(t % 2 == 0);
	return t / 2;
}

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &N, &W); W *= 2;
		for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]), Nr[i][j] *= 2;
		int val = solve();
		if(val == -1) puts("IMPOSSIBLE"); else printf("%d\n", val);
	}
	return 0;
}