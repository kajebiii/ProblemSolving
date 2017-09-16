#include <stdio.h>
#include <algorithm>

using namespace std;

struct PT
{
	int x, y;
};

int N[2];
PT Ps[2][200];

long double getD(PT &a, PT &b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}
long double getPS(PT &a, PT &x, PT &y)
{
	long double n = getD(a, x), m = getD(a, y), o = getD(x, y);
	if((n*n - m*m - o*o) < 0 && (m*m - n*n - o*o) < 0)
	{
		PT d; d.x = a.x - x.x; d.y = a.y - x.y;
		PT l; l.x = y.y - x.y; l.y = -y.x + x.x;
		return (long double)abs(d.x * l.x + d.y * l.y) / o;
	}
	else return min(n, m);
}
long double getSS(PT &a, PT &b, PT &x, PT &y)
{
	long double aa = min(getPS(a, x, y), getPS(b, x, y));
	long double bb = min(getPS(x, a, b), getPS(y, a, b));
	return min(aa, bb);
}

int main()
{
	int TC; scanf("%d", &TC);
	for(int t=1; t<=TC; t++)
	{
		for(int k=0; k<2; k++)
		{
			scanf("%d", &N[k]);
			for(int i=0; i<N[k]; i++)
				scanf("%d%d", &Ps[k][i].x, &Ps[k][i].y);
			Ps[k][N[k]].x = Ps[k][0].x;
			Ps[k][N[k]].y = Ps[k][0].y;
		}
		long double ans = 100000;
		for(int i=0; i<N[0]; i++) for(int j=0; j<N[1]; j++)
			ans = min(ans, getSS(Ps[0][i], Ps[0][i+1], Ps[1][j], Ps[1][j+1]));
		printf("%.15Lf\n", ans/2);
	}
	return 0;
}