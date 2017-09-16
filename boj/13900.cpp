#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;


int main()
{
	int N;
	ll sum = 0, sums = 0;
	scanf("%d", &N);
	for(int i=0, x; i<N; i++)
	{
		scanf("%d", &x);
		sum += x;
		sums += 1ll * x * x;
	}
	sum = sum * sum;
	printf("%lld\n", (sum - sums)/2);
	return 0;
}