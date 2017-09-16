#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100, MOD = 1e9 + 7;

int One[MAX_N], Two[MAX_N], N;
ll Dy[MAX_N][2];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &One[i]);
	for(int i=2; i<=N; i++) scanf("%d", &Two[i]);

	Dy[0][0] = 1;
	for(int i=1; i<=N; i++)
	{
		Dy[i][0] = (Dy[i-1][0] + Dy[i-1][1]) * One[i] % MOD;
		Dy[i][0] += Dy[i-1][0] * Two[i] % MOD;
		if(Two[i] >= 1) Dy[i][0] += Dy[i-1][1] * (Two[i] - 1) % MOD;
		Dy[i][0] %= MOD;
		if(Two[i+1] >= 1)
			Dy[i][1] = (Dy[i-1][0] + Dy[i-1][1]) * Two[i+1] % MOD;
	}
	printf("%lld\n", (Dy[N][0] + Dy[N][1]) % MOD);
	return 0;
}