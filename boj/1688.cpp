#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 100;
typedef long long ll;

struct POINT
{
	int x, y;
	POINT(int x_, int y_):x(x_), y(y_){};
	POINT():x(0),y(0){}
	const bool operator<(POINT &o) const
	{
		if(x == o.x) return y < o.y;
		return x < o.x;
	}
};
int N; POINT P[MAX_N];

int ccw(int a, int b, int c)
{
	int dx0 = P[b].x - P[a].x, dx1 = P[c].x - P[a].x;
	int dy0 = P[b].y - P[a].y, dy1 = P[c].y - P[a].y;
	ll val = 1ll * dx0 * dy1 - 1ll * dx1 * dy0;
	if(val != 0) val /= abs(val);
	return val;
}
bool checkIn(int a, int b, int c)
{
	int isccw = ccw(a, b, c);
	if(isccw != 0) return false;
	POINT S[3] = {P[a], P[b], P[c]};
	sort(S, S+3);
	if(P[a].x == S[1].x && P[a].y == S[1].y) return true;
	return false;
}
bool inter(int a, int b, int c, int d)
{
	return ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N+3; i++) scanf("%d%d", &P[i].x, &P[i].y);
	for(int j=N; j<N+3; j++)
	{
		int isIn = false, isInLine = false;;
		P[N+3] = POINT(P[j].x+1, P[j].y+1e9+1);
		for(int i=0; i<N; i++)
		{
			isIn ^= inter(j, N+3, i, (i+1)%N);
			if(checkIn(j, i, (i+1)%N)) isInLine = true;
		}
		printf("%d\n", isInLine?1:isIn?1:0);
	}
	return 0;
}