#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 10;
typedef long long ll;

struct PT
{
	int x, y;
	PT() : x(0), y(0) {}
	PT(int x_, int y_) : x(x_), y(y_) {}
};

int gccw(PT &a, PT &b, PT &c)
{
	int dx[2] = {b.x - a.x, c.x - a.x};
	int dy[2] = {b.y - a.y, c.y - a.y};
	ll val = 1ll * dx[0] * dy[1] - 1ll * dx[1] * dy[0];
	if(val == 0) return 0;
	return val/abs(val);
}

vector<PT> Ps; int N, P;

int main()
{
	scanf("%d", &N); scanf("%d", &P);
	for(int i=0; i<N; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		Ps.push_back(PT(x, y));
	}
	for(int p=0; p<500; p++)
	{
		int cnt = 0;
		int a = rand() % N, b = rand() % N-1;
		if(b >= a) b++;
		for(int i=0; i<N; i++)
			if(gccw(Ps[a], Ps[b], Ps[i]) == 0)
				cnt++;

		if(cnt >= (N * P + 99) / 100)
		{
			puts("possible");
			return 0;
		}
	}
	puts("impossible");
	return 0;
}