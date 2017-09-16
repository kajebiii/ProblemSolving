#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int N, mx = -1, sum = 0, ix = -1;
	scanf("%d", &N);
	for(int i=1, x; i<=N; i++) 
	{
		scanf("%d", &x), mx = max(mx, x), sum += x;
		if(mx == x) ix = i;
	}
	if(sum - mx >= mx)
	{
		printf("%d ", ix-1 + 1);
		for(int i=1; i<N; i++) printf("%d ", (ix-1 + i) % N + 1);
	}
	else puts("impossible");
	return 0;
}