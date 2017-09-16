#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll F[88];

int main() {
	int N; scanf("%d", &N);
	F[0] = F[1] = 1;
	for(int i=2; i<=N+1; i++) F[i] = F[i-1] + F[i-2];
	printf("%lld\n", F[N+1]*2);
	return 0;
}