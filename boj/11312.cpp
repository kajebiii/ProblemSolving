#include <stdio.h>
#include <algorithm>

using namespace std;

int T, A, B;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &A, &B);
		printf("%lld\n", 1ll * A * A / B / B);
	}
	return 0;
}