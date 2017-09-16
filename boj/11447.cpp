#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		double nowX = 0;
		double val = 0, sq3 = sqrt(3);
		for(int i=0; i<N; i++) {
			char c[3]; int d;
			scanf("%s%d", c, &d);
			if(c[0] == 'x') nowX += d;
			else {
				if(c[0] == 'y') {
					val += (sq3 / 2 * nowX * d + sq3 / 8 * d * d);
					nowX += (double)d / 2;
				}
				if(c[0] == 'z') {
					val += (sq3 / 2 * nowX * d - sq3 / 8 * d * d);
					nowX -= (double)d / 2;
				}
			}
		}
		val = abs(val);
		printf("%lld\n", (long long)(val / sq3 * 4 + 0.5) );
	}
	return 0;
}