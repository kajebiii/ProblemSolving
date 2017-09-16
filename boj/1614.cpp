#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll H, N; scanf("%lld%lld", &H, &N);
	if(H == 1)
		printf("%lld\n", N*8);
	else if(H == 5)
		printf("%lld\n", N*8+4);
	else
	{
		if(N % 2 == 0)
			printf("%lld\n", N/2*8 + H-1);
		else
			printf("%lld\n", N/2*8 + 5-H + 4);
	}
	return 0;
}