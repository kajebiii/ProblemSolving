#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10, MAX_AS = 5e2, INF = 0x7fffffff;

int N, L;
int A[MAX_N], C[MAX_N];
int Dy[MAX_N][MAX_AS + 1];

int main()
{
	scanf("%d%d", &N, &L);
	int AS = 0, CS = 0;
	for(int i=1; i<=N; i++) scanf("%d", &A[i]), AS += A[i];
	for(int i=1; i<=N; i++) scanf("%d", &C[i]), CS += C[i];

	for(int i=0; i<=N; i++) for(int j=0; j<=AS; j++) Dy[i][j] = INF;
	Dy[0][0] = 0;
	for(int i=1; i<=N; i++) for(int k=i; k>=1; k--) for(int j=A[i]; j<=AS; j++)
		if(Dy[k-1][j-A[i]] != INF)
			Dy[k][j] = min(Dy[k][j], Dy[k-1][j-A[i]] + C[i]);
	
	double ans = 1ll * INF * INF; 
	int next = N-2*L; if(next == 0) next = 1;
	for(int i=L; i==L || i==N-L; i+=next)
		for(int j=0; j<=AS; j++) if(Dy[i][j] != INF)
			ans = min(ans, (double)1.0 * (CS-Dy[i][j]) * Dy[i][j] / (AS - j) / j);
	printf("%.3lf\n", ans);

	return 0;
}