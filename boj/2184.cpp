#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10, INF = 0x7fffffff;

int N, Nr[MAX_N], S;
int Dy[MAX_N][MAX_N][2];

int main()
{
	scanf("%d%d", &N, &S); for(int i=0; i<N; i++) scanf("%d", &Nr[i]); Nr[N++] = S;
	sort(Nr, Nr+N);
	int ix = -1; for(int i=0; i<N; i++) if(Nr[i] == S) ix = i;

	for(int p=N-2; p>=0; p--)
	{
		int cnt = N - p - 1;
		for(int i=0, j=p; j<N; i++, j++)
		{
			Dy[i][j][0] = Dy[i][j][1] = INF;
			if(j < ix || i > ix) continue;
			for(int k=0; k<2; k++) for(int fr=0; fr<2; fr++)
			{
				int l = i - 1 + fr, r = j + fr;
				if(l < 0 || r >= N) continue;
				if(Dy[l][r][fr] == INF) continue;
				int a = (fr == 0 ? l : r), b = (k == 0 ? i : j);
				Dy[i][j][k] = min(Dy[i][j][k], Dy[l][r][fr] + abs(Nr[a] - Nr[b]) * cnt);
			}
		}
	}
	printf("%d\n", Dy[ix][ix][0]);
	return 0;
}