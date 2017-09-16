#include <stdio.h>

const int MAX_N = 1e2 + 10;
int N, M, K; char Mp[MAX_N][MAX_N]; int S[MAX_N][MAX_N];
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%s", Mp[i] + 1);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (Mp[i][j] == '*');
	int ans = -1, ansi, ansj;
	for(int i=K; i<=N; i++) for(int j=K; j<=M; j++)
	{
		int now = S[i-1][j-1] - S[i-K+1][j-1] - S[i-1][j-K+1] + S[i-K+1][j-K+1];
		if(ans < now)
		{
			ans = now;
			ansi = i;
			ansj = j;
		}
	}
	for(int i=1; i<=K-2; i++) Mp[ansi][ansj-i] = Mp[ansi-K+1][ansj-i] = '-';
	for(int i=1; i<=K-2; i++) Mp[ansi-i][ansj] = Mp[ansi-i][ansj-K+1] = '|';
	Mp[ansi][ansj] = Mp[ansi-K+1][ansj] = Mp[ansi][ansj-K+1] = Mp[ansi-K+1][ansj-K+1] = '+';
	printf("%d\n", ans);
	for(int i=1; i<=N; i++) printf("%s\n", Mp[i]+1);
	return 0;
}