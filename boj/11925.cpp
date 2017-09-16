#include <stdio.h>

const int MOD = 1e9;

int N, Cnt[22][22], P[501];
int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=i; j<N; j++)
		for(int x=i; x<=j; x++) for(int y=x+1; y<=j; y++)
			if(gcd(x+1, y+1) == 1) Cnt[i][j]++;
	P[0] = 1; for(int i=1; i<=500; i++) P[i] = (P[i-1] * 2) % MOD;

	int ans = 0;
	for(int p=0; p<(1<<(N-1)); p++)
	{
		int l = 0, now = 1, cnt = 0;
		for(int i=0; i<N; i++)
		{
			if(i == N-1 || (p & (1<<i)) > 0)
			{
				now = 1ll * now * P[Cnt[l][i]] % MOD;
				l = i+1;
				cnt++;
			}
		}
		if(cnt % 2 == 0) cnt = -1; else cnt = 1;
		now -= 1;
		ans += cnt * now;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}