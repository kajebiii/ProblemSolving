#include <stdio.h>

int N, K;

int main()
{
	scanf("%d%d", &N, &K);

	long long l = 1, r = 1ll * N * N;
	while(l < r)
	{
		long long m = (l + r) / 2;
		long long cnt = 0;
		for(int i=1; i<=N; i++) cnt += m / i < N ? m / i : N;
		if(cnt < K) l = m + 1;
		else r = m;
	}
	printf("%lld\n", l);

	return 0;
}