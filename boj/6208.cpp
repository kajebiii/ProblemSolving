#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 100, INF = 0x7fffffff;

int L, N, B;
struct LINE
{
	int x, w, f, c;
	LINE(){}
	LINE(int x, int w, int f, int c):x(x), w(w), f(f), c(c){}
	const bool operator<(const LINE &o) const
	{
		return x < o.x;
	}
}Li[MAX_N];
int Dy[1111][1111];

int main()
{
	scanf("%d%d%d", &L, &N, &B);
	for(int i=0, x, w, f, c; i<N; i++)
		scanf("%d%d%d%d", &x, &w, &f, &c), Li[i] = LINE(x, w, f, c);
	sort(Li, Li+N);
	for(int i=0; i<=L; i++) for(int j=0; j<=B; j++) Dy[i][j] = -INF;
	Dy[0][0] = 0;
	for(int p=0; p<N; p++)
	{
		int x = Li[p].x, w = Li[p].w, f = Li[p].f, c = Li[p].c;
		for(int j=0; j<=B-c; j++)
			Dy[x+w][j+c] = max(Dy[x+w][j+c], Dy[x][j] + f);
	}
	int ans = -1;
	for(int i=0; i<=B; i++) ans = max(ans, Dy[L][i]);
	printf("%d\n", ans);
	return 0;
}