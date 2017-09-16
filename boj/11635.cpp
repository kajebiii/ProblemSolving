#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll ee(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1; y = 0;
		return a;
	}
	ll q = a/b, r = a%b, nx, ny;
	ll g = ee(b, r, nx, ny);
	// (b * nx) + (a - b*q)*ny;
	x = ny; y = nx - q * ny;
	return g;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		ll r, s, q; scanf("%lld%lld%lld", &r, &s, &q); s *= -1;
		ll g, a, b; g = ee(r, s, a, b);
//		printf("%lld * %lld + %lld * %lld = %lld\n", r, a, s, b, g);
		ll multi = q / g;
		a *= multi; b *= multi; 
		ll ak = s / g, bk = r / g; // a + ak * k, b - bk * k;
		// we need a >= 1, b <= -1;
		if(a > 0) {
			ll k = (a - 1) / ak;
			a -= ak * k;
			b += bk * k;
		}else {
			ll k = (-a) / ak + 1;
			a += ak * k;
			b -= bk * k;
		}
		if(b >= 0) {
			ll k = b / bk + 1;
			a += ak * k;
			b -= bk * k;
		}

		b *= -1;
		printf("%lld %lld\n", a, b);
	}
	return 0;
}