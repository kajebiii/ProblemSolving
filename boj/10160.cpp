#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 100, MOD = 1e9 + 9;

int N, K;
int Dy[MAX_N][8];
int Auto[8][4], Cnt[4];

void add(int v, char x, int w)
{
	Auto[v][x-'A'] = w;
}
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<8; i++) for(int j=0; j<4; j++) Auto[i][j] = 0;
	for(int i=0; i<8; i++) Auto[i][0] = 1;
	for(int i=0; i<4; i++) Auto[7][i] = 7;
	add(1, 'B', 2);
	add(2, 'A', 3);
	add(2, 'C', 5);
	add(3, 'B', 4);
	add(4, 'A', 3);
	add(4, 'C', 7);
	add(5, 'B', 6);
	add(6, 'C', 7);

	Dy[0][0] = 1;
	for(int i=0; i<min(K, 4); i++) Cnt[i] = 1;
	if(K >= 4) Cnt[3] = K - 3;
	for(int i=1; i<=N; i++)
		for(int j=0; j<8; j++) for(int k=0; k<4; k++)
			Dy[i][Auto[j][k]] = (Dy[i][Auto[j][k]] + 1ll * Dy[i-1][j] * Cnt[k]) % MOD;
	int ans = 0;
	for(int j=0; j<7; j++) ans = (ans + Dy[N][j]) % MOD;
	printf("%d\n", ans);
	return 0;
}