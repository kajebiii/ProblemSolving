#include <stdio.h>
#include <algorithm>

const int MAX_N = 5e4 + 100;

int Minus[MAX_N];

int main() {
	Minus[0] = -1;
	for(int i=1; i<=MAX_N; i++) Minus[i] = Minus[i-1] + i*2-1;

	int T; scanf("%d", &T);
	while(T--) {
		int x, y; scanf("%d%d", &x, &y);
		if(y > x/2) y = x - y;
		printf("%d\n", x*y - Minus[y]);
	}
	return 0;
}