#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll get(ll n) {
	ll res = 0;
	for(int p=0; p<62; p++) {
		res += (n / (1ll<<p+1)) * (1ll<<p);
		ll rest = n % (1ll<<p+1);
		res += (rest >= (1ll<<p))?rest-(1ll<<p)+1:0;
	}
	return res;
}
int main() {
	ll A, B; scanf("%lld%lld", &A, &B);
	printf("%lld\n", get(B) - get(A-1));
	return 0;
}