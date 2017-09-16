#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		long long x; scanf("%lld", &x);
		long long k = sqrt(x);
		if(k * k == x) printf("1 "); else printf("0 ");
	}
	return 0;
}