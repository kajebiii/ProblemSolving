#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll N; int Ch[64];

int main() {
	scanf("%lld", &N);
	ll r = -1;
	for(int i=63; i>=0; i--) Ch[i] = N % 2, N /= 2;

	next_permutation(Ch, Ch+64);
	ll Ans = 0;
	for(int i=0; i<=63; i++) Ans *= 2, Ans += Ch[i];
	r = Ans;
	prev_permutation(Ch, Ch+64);
	if(prev_permutation(Ch, Ch+64) == false) printf("0 ");
	else {
		ll Ans = 0;
		for(int i=0; i<=63; i++) Ans *= 2, Ans += Ch[i];
		printf("%lld ", Ans);
	}
	printf("%lld\n", r);
	return 0;
}