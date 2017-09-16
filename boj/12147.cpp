#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		int R, C, W; scanf("%d%d%d", &R, &C, &W);
		int c = C, ans = 0;
		while(c-W >= W) c-= W, ans++;
		ans *= R; ans += R-1;
		ans += min(W+1, c);
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}