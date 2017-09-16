#include <stdio.h>

int main()
{
	int N; scanf("%d", &N);
	
	long long ans = 0;
	for(int i=0, x; i<100; i++)
		scanf("%d", &x), ans += x;
	printf("100\n%lld\n", ans);
	return 0;
}