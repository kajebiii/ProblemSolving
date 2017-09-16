#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

ll N;

int main()
{
	scanf("%lld", &N);
	if(N == 1) printf("0\n");
	else printf("%lld\n", (N+1) / 2);
	return 0;
}