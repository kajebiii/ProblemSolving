#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_N = 1e6 + 100;

int N, B, X, Y;
double Nr[MAX_N];
double getDis2(int x, int y) {
	int dx = x - X, dy = y - Y;
	return 1ll * dx * dx + 1ll * dy * dy;
}
double getNr(int x, int y, int s) {
	return s / getDis2(x, y);
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d%d%d", &N, &B, &X, &Y);

		double maxV = -1, sumV = B; int maxIx = -1;
		for(int i=1; i<=N; i++) {
			int x, y, s; scanf("%d%d%d", &x, &y, &s);
			Nr[i] = getNr(x, y, s);
			if(maxV < Nr[i]) { maxV = Nr[i]; maxIx = i; }
			sumV += Nr[i];
		}
		if(maxIx == -1) {puts("NOISE"); continue;}
		sumV -= Nr[maxIx];
		sumV *= 6;

		if(maxV > sumV) printf("%d\n", maxIx); else puts("NOISE");
	}
	return 0;
}