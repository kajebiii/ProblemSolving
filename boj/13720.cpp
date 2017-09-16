#include <stdio.h>
#include <algorithm>

using namespace std;

int Nr[111][111];
int main()
{
	int N; scanf("%d", &N);
	if(N%2==1)
		for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; j++) printf("%d ", i*N-N+j);
	else
	{
		if(N == 2)
		{
			printf("-1\n");
			return 0;
		}
		for(int i=1; i<N; i++) Nr[1][i] = i; Nr[1][N] = (N-1) * N / 2;
		for(int i=2; i<N; i++) for(int j=1; j<=N; j++) Nr[i][j] = Nr[i-1][j] + Nr[1][N] * 2;
		for(int i=1; i<=N; i++) Nr[N][i] = Nr[1][i] + (N+1)*N*(N-1)*(N-2)/2;
		for(int i=1; i<=N; i++, puts("")) for(int j=1; j<=N; j++) printf("%d ", Nr[i][j]);
	}
	return 0;
}