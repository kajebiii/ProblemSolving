#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 35;

ll D[MAX_N + 1];
int main()
{
	D[0] = 1;
	int N; scanf("%d", &N);
	for(int i=1; i<=N; i++) for(int j=0; j<=i-1; j++) D[i] += D[j] * D[i-1-j];
	printf("%lld\n", D[N]);
	return 0;
}