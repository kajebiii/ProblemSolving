#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 1e2 + 10, MOD = 1e9 + 9;

int L, N, F[MAX_N];
char S[MAX_N];
int Auto[MAX_N][2];
int Dy[MAX_N][MAX_N][MAX_N]; //x, auto, h;
map<char, int> Mp;

int main()
{
	Mp['D'] = 0, Mp['U'] = 1;
	scanf("%d", &L); scanf(" ");
	if(L % 2 == 1) {printf("0"); return 0; }
	scanf("%s", S); N = strlen(S);
	F[0] = -1; for(int i=0, j=-1; i<N; (j<0 || S[i] == S[j]) ? F[++i] = ++j : j = F[j]);
	Auto[0][Mp[S[0]]] = 1;
	for(int i=1; i<N; i++)
	{
		for(int m=0; m<2; m++)
			Auto[i][m] = Auto[F[i]][m];
		Auto[i][Mp[S[i]]] = i+1;
	}
	for(int m=0; m<2; m++) Auto[N][m] = N;

	Dy[0][0][0] = 1;
	for(int i=1; i<=L; i++) for(int j=0; j<=N; j++)
		for(int h=0; h<=i; h++) for(int k=0; k<2; k++)
		{
			int dh = k*2 - 1;
			if(h + dh < 0) continue;
			Dy[i][Auto[j][k]][h+dh] += Dy[i-1][j][h];
			Dy[i][Auto[j][k]][h+dh] %= MOD;
		}
	printf("%d\n", Dy[L][N][0]);
	return 0;
}