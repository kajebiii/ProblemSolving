#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_F = 45, INF = 0x7fffffff;
typedef long long ll;
typedef pair<int, int> pi;

int ee(int a, int b, int &x, int &y) {
	if(b == 0) {x = 1; y = 0; return a;}
	int q = a / b, r = a % b, gx, gy;
	int g = ee(b, r, gx, gy);
	x = gy; y = gx - q * gy;
	return g;
}

int N, F[99];

const int debug = 0, fre = 0;
int main() {
	if(fre) { freopen("input.txt", "r", stdin); }
	F[0] = 1; F[1] = 0;
	for(int i=2; i<=MAX_F+1; i++) F[i] = F[i-1] + F[i-2];
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d", &N);
		pi ans = make_pair(INF, INF);
		for(int i=1; i<=MAX_F; i++) {
			int x, y;
			int g = ee(F[i-1], F[i], x, y);
			ll a = 1ll * x * N, b = 1ll * y * N;
			if(a < b) {
				ll pk = (b-a + F[i] - 1) / F[i];
				a += pk * F[i];
				b -= pk * F[i-1];
			}
			ll k = (a - b + F[i+1] - 1) / F[i+1];
			a -= 1ll * F[i] * k;
			b += 1ll * F[i-1] * k;
			if(debug) printf("%d * %lld + %d * %lld = %d\n", F[i-1], a, F[i], b, N);
			if(0 < a)
				if(ans.second > b || (ans.second == b && ans.first > a))
					ans = make_pair(a, b);
		}
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}