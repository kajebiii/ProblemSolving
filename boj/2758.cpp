#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e3 + 10, MAX_L = 22;

ll Dy[MAX_N][MAX_L];

int main()
{
	for(int i=1; i<=2000; i++) Dy[i][1] = 1;
	for(int i=1; i<=2000; i++)
	{
		for(int j=1; j<=i/2; j++)
			for(int k=1; k<=9; k++)
				Dy[i][k+1] += Dy[j][k];
	}
	for(int k=1; k<=10; k++) for(int i=1; i<=2000; i++) Dy[i][k] += Dy[i-1][k];

	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		printf("%lld\n", Dy[m][n]);
	}
	return 0;
}