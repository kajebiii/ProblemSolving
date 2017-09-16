#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

long long D, X, Y;
int main() {
//	freopen("output.txt", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld", &D, &X, &Y);
		long long v = X*X+Y*Y;
		double val = sqrt((double)v / D);

		int ans = -1;
		for(int i=max(0, (int)val - 10); i<=(int)val + 10; i++) {
			if(v <= D * i * i) {
				ans = i;
				break;
			}
		}
		if(ans == 1)
			if(D != v) ans++;
		printf("%d\n", ans);
	}
	return 0;
}