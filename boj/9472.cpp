#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 17;

int N; ll Dy[MAX_N+1][MAX_N+2];

int main()
{
	Dy[0][0] = Dy[0][1] = 1;
	for(int i=2; i<=MAX_N; i++) Dy[i][i] = Dy[i][i+1] = (Dy[i-2][i-2] + Dy[i-1][i-1]) * (i-1);
	for(int i=1; i<=MAX_N; i++)
		for(int j=i-1; j>=0; j--)
			Dy[i][j] = Dy[i][j+1] + Dy[i-1][j];
	int tc; scanf("%d", &tc);
	while(tc--)
	{
		int t, n, k; scanf("%d%d%d", &t, &n, &k);
		printf("%d %lld\n", t, Dy[n][k]);
	}
	return 0;
}