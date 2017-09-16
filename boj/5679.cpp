#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	while(1)
	{
		int N; scanf("%d", &N);
		if(N == 0) break;
		int ans = N;
		while(N != 1)
		{
			if(N % 2 == 0) N /= 2;
			else N = 3 * N + 1;
			ans = max(ans, N);
		}
		printf("%d\n", ans);
	}
	return 0;
}