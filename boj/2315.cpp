#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 100, INF = 0x7fffffff;

int N, M, Sum[MAX_N];
int Dy[MAX_N][MAX_N][2];

struct LAMP
{
	int x, w, ix;
	LAMP() {}
	LAMP(int x_, int w_, int i_) : x(x_), w(w_), ix(i_) {}
};
LAMP Ls[MAX_N];
int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
	{
		int x, w; scanf("%d%d", &x, &w);
		Ls[i] = LAMP(x, w, i);
	}
	for(int i=1; i<=N; i++) Sum[i] = Sum[i-1] + Ls[i].w;

	int last = M;
	for(int p=N-1; p>=0; p--) for(int i=1; i+p<=N; i++) for(int k=0; k<2; k++) Dy[i][i+p][k] = INF;
	Dy[1][N][0] = Dy[1][N][1] = 0;
	Ls[0].x = Ls[N+1].x = INF;
	for(int p=N-2; p>=0; p--)
		for(int i=1; i+p<=N; i++)
		{
			int j = i+p;
			if(last < i || j < last) continue;
			LAMP past[2] = {Ls[i-1], Ls[j+1]};
			LAMP now[2] = {Ls[i], Ls[j]};

			int nowS = Sum[j] - Sum[i-1], rest = Sum[N] - nowS;
			for(int go=0; go<2; go++) for(int from=0; from<2; from++) if(past[go].x != INF)
				Dy[i][j][from] = min(Dy[i][j][from], Dy[i-1+go][j+go][go] + rest * abs(past[go].x - now[from].x));

//			printf("%d %d : [%d %d]\n", i, j, Dy[i][j][0], Dy[i][j][1]);
		}
	printf("%d\n", Dy[last][last][0]);
	return 0;
}