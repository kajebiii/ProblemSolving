#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e2 + 10, INF = 0x7fffffff;

int N;
struct QUE
{
	int x, y;
	int s, ix;
};

int Dy[MAX_N][MAX_N], Cnt[MAX_N][MAX_N];
QUE Xs[MAX_N], Ys[MAX_N];
int XY[MAX_N][2];

int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d%d%d", &Xs[i].x, &Xs[i].y, &Xs[i].s); Xs[i].ix = i;
		Ys[i] = Xs[i];
	}
	sort(Xs+1, Xs+N+1, [&](QUE &a, QUE &b) {return a.x < b.x;});
	sort(Ys+1, Ys+N+1, [&](QUE &a, QUE &b) {return a.y < b.y;});
	for(int i=1; i<=N; i++)
	{
		XY[Xs[i].ix][0] = i;
		XY[Ys[i].ix][1] = i;
	}
	Xs[0].x = 1; Ys[0].y = 1; Dy[0][0] = 0;

	int ans = 0;
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++)
	{
		if(i+j == 0) continue;
		Dy[i][j] = -INF;
		if(i>0 && Dy[i-1][j] + Xs[i-1].x >= Xs[i].x)
			Dy[i][j] = max(Dy[i][j], Dy[i-1][j] - (Xs[i].x - Xs[i-1].x) + (XY[Xs[i].ix][1] > j ? Xs[i].s : 0) );
		if(j>0 && Dy[i][j-1] + Ys[j-1].y >= Ys[j].y)
			Dy[i][j] = max(Dy[i][j], Dy[i][j-1] - (Ys[j].y - Ys[j-1].y) + (XY[Ys[j].ix][0] > i ? Ys[j].s : 0) );
		if(i>0)
			Cnt[i][j] = Cnt[i-1][j] + (XY[Xs[i].ix][1] > j ? 1 : 0);
		if(j>0)
			Cnt[i][j] = Cnt[i][j-1] + (XY[Ys[j].ix][0] > i ? 1 : 0);
		if(Dy[i][j] != -INF)
			ans = max(ans, Cnt[i][j]);
	}

	printf("%d\n", ans);

	return 0;
}