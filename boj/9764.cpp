#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 2e3 + 100, MOD = 100999;

int Dy[MAX_N][MAX_N];
int main()
{
	Dy[0][0] = 1;
	for(int i=1; i<=2000; i++) Dy[0][i] = 1;
	for(int i=1; i<=2000; i++) 
	{
		for(int j=1; j<=i; j++)
			Dy[i][j] = (Dy[i][j] + Dy[i-j][j-1]) % MOD;
		for(int j=1; j<=2000; j++)
			Dy[i][j] = (Dy[i][j] + Dy[i][j-1]) % MOD;
	}
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);
		printf("%d\n", Dy[N][N]);
	}
	return 0;
}