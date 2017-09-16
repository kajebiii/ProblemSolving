#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MOD = 1e9 + 7;

int K, L; char S[3333];
int Dy[3333][3333];

int main()
{
	scanf("%d%s", &K, S+1); L = strlen(S+1);
	Dy[0][K] = 1;
	for(int i=1; i<=L; i++)
		for(int l=25; l>=0; l--)
			for(int j=l; j<=K; j++)
				Dy[i][j-l] += Dy[i-1][j], Dy[i][j-l] %= MOD;
	printf("%d\n", Dy[L][0]);
	return 0;
}