#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

const int MAX_S = 5e4 + 100, MAX_N = 1e2 + 20, BASE = 110;

int SN; char S[MAX_S], Mp[MAX_N * 2][MAX_N];

const int debug = 0, fre = 0;
int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC); printf("%d\n", TC);
	while(TC--) {
		scanf("%s", S+1); SN = strlen(S+1);
		for(int i=0; i<2*MAX_N; i++) for(int j=0; j<MAX_N; j++) Mp[i][j] = '#';
		int x = BASE, y = 0, d = 0;
		int xm = x, xM = x, ym = y, yM = y;
		auto calc = [&](int a, int b) {
			xm = min(xm, a); xM = max(xM, a);
			ym = min(ym, b); yM = max(yM, b);
		};
		// "1210", "2101"
		Mp[x][y] = '.';
		for(int i=1; i<=SN; i++) {
			if(S[i] == 'R') d = (d+1) % 4;
			if(S[i] == 'L') d = (d+3) % 4;
			if(S[i] == 'B') d = (d+2) % 4;
			x += "1210"[d] - '1';
			y += "2101"[d] - '1';
			Mp[x][y] = '.';
			calc(x, y);
		}
		int N = (xM+1) - (xm-1) + 1, M = (yM+1) - (ym) + 1;
		printf("%d %d\n", N, M);
		for(int i=xm-1; i<=xM+1; i++, puts("")) for(int j=ym; j<=yM+1; j++)
			printf("%c", Mp[i][j]);
	}
	return 0;
}