#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 6e2 + 10, INF = 0x7fffffff;

int N, Pt[MAX_N][2];
double Dy[MAX_N][MAX_N];

double getDis(int i, int j)
{
	int dx = Pt[i][0] - Pt[j][0];
	int dy = Pt[i][1] - Pt[j][1];
	return sqrt(dx * dx + dy * dy);
}
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i=1; i<=N; i++) scanf("%d%d", &Pt[i][0], &Pt[i][1]);
		for(int i=1; i<=N; i++) for(int j=1; j<=i; j++) Dy[i][j] = INF;
		Dy[1][1] = 0;
		for(int i=2; i<=N; i++)
		{
			for(int j=1; j<i; j++) Dy[i][j] = min(Dy[i][j], Dy[i-1][j] + getDis(i, i-1));
			for(int j=1; j<i; j++) Dy[i][i-1] = min(Dy[i][i-1], Dy[i-1][j] + getDis(j, i));
			for(int j=1; j<i; j++) Dy[i][i] = min(Dy[i][i], Dy[i][j] + getDis(j, i));
		}
		printf("%.6lf\n", Dy[N][N]);
	}
	return 0;
}