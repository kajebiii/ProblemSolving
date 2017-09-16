#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

bool solve(ll a, ll b) {
	if(a < b) return solve(b, a);
	if(a % b == 0) return true;
	if(a / b > 1) return true;
	return !solve(b, a-b);
}
int main() {
	ll A, B; scanf("%lld%lld", &A, &B);
	puts(solve(A, B)?"win":"lose");
	return 0;
}