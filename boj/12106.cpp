#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10, MOD = 1e9 + 9;

int L, N, F[MAX_N];
char S[MAX_N];
int Auto[MAX_N][26];
int Dy[MAX_N][MAX_N];

int main()
{
	scanf("%d", &L); scanf(" ");
	scanf("%s", S); N = strlen(S);
	F[0] = -1; for(int i=0, j=-1; i<N; (j<0 || S[i] == S[j]) ? F[++i] = ++j : j = F[j]);
	Auto[0][S[0] - 'a'] = 1;
	for(int i=1; i<N; i++)
	{
		for(int m=0; m<26; m++)
			Auto[i][m] = Auto[F[i]][m];
		Auto[i][S[i] - 'a'] = i+1;
	}
	for(int m=0; m<26; m++) Auto[N][m] = N;

	Dy[0][0] = 1;
	for(int i=1; i<=L; i++)
		for(int j=0; j<=N; j++)
			for(int m=0; m<26; m++)
				Dy[i][Auto[j][m]] = (Dy[i][Auto[j][m]] + Dy[i-1][j]) % MOD;
	printf("%d\n", Dy[L][N]);
	return 0;
}