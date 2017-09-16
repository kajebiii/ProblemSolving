#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll N; 
	while(scanf("%lld", &N) == 1)
	{
		if(N == 0) break;
		printf("%lld\n", N*(N+1)*(N+2)/6);
	}
	return 0;
}