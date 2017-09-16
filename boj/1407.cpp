#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll A, B;

int main()
{
	scanf("%lld%lld", &A, &B);
	ll ans = B - A + 1;
	for(ll p=2; p<=B; p<<=1)
	{
		ll cnt = B / p - (A-1) / p;
		ans += cnt * (p/2);
	}
	printf("%lld\n", ans);
	return 0;
}