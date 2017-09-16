#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

int main()
{
	ll X, Y; scanf("%lld%lld", &X, &Y);
	X = Y - X;
	ll base = sqrt(X) * 2;
	
	for(ll i=max(0ll, base-100); i<=base+100; i++)
	{
		ll now = (i/2+1) * (i/2+1);
		if(i % 2 == 0) now -= (i+2)/2;
		if(now >= X)
		{
			printf("%lld\n", i);
			return 0;
		}
	}
	return 0;
}