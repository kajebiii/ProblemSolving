#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		int last = 1, now = 0, ans = 0;
		while(scanf("%d", &now) == 1) {
			if(last * 2 < now) ans += (now - last * 2);
			last = now;
			if(now == 0) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}