#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <map>
#include <tuple>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		int N, A, B, C, D; scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);

		double X = 0, Y = 0, XY = 0, ans = 0;
		for(int n=1; n<=N; n++) {
			XY = (XY * (2*A + 2*C + B + D) + X * D + Y * B) / 100;
			X = (X * (2*A + B + C + D) + B) / 100;
			Y = (Y * (A + B + 2*C + D) + D) / 100;
			ans += XY;
		}
		printf("%.10f\n", ans);
	}
	return 0;
}
