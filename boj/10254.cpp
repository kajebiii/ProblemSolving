#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef long long ll;

struct PT
{
	int x, y;
	PT() : x(0), y(0) {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(PT &o){return PT(x-o.x, y-o.y);}
};

int ccw(PT &a, PT &b, PT &c)
{
	int x[2] = {b.x - a.x, c.x - a.x};
	int y[2] = {b.y - a.y, c.y - a.y};
	ll val = 1ll*x[0]*y[1] - 1ll*x[1]*y[0];
	return val==0?0:val>0?1:-1;
}

int N;
vector<PT> Ps, cv;

ll getDis(PT &a, PT &b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return 1ll*dx*dx + 1ll*dy*dy;
}
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		Ps.clear(); cv.clear();
		for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Ps.push_back(PT(x, y));
		for(int i=1; i<N; i++) if(i==0 || Ps[0].y > Ps[i].y || (Ps[0].y == Ps[i].y && Ps[0].x > Ps[i].x)) swap(Ps[0], Ps[i]);
		sort(Ps.begin()+1, Ps.end(), [&](PT &a, PT &b)
		{
			int val = ccw(Ps[0], a, b);
			if(val > 0) return true;
			if(val < 0) return false;
			return a.y-Ps[0].y + abs(a.x-Ps[0].x) < b.y-Ps[0].y + abs(b.x-Ps[0].x);
		});
		cv.push_back(Ps[0]);
		for(int i=1; i<N; cv.push_back(Ps[i]), i++)
			while(cv.size() >= 2 && ccw(cv[cv.size()-2], cv[cv.size()-1], Ps[i]) <= 0) cv.pop_back();


		ll ans = 0; int ixi=0, ixj=0;
		int cN = cv.size();
		for(int i=0, j=1; i<cN; i++)
		{
			int ni = (i+1) % cN, nj = (j+1) % cN;
			while(1)
			{
				PT a = PT(0, 0), b = cv[ni] - cv[i], c = cv[nj] - cv[j];
				int val = ccw(a, b, c);
				ans = max(ans, getDis(cv[i], cv[j]));
				if(ans == getDis(cv[i], cv[j])) ixi=i, ixj=j;
				if(val <= 0) break;
				j = (j + 1) % cN;
				nj = (j + 1) % cN;
			}
		}
		printf("%d %d %d %d\n", cv[ixi].x, cv[ixi].y, cv[ixj].x, cv[ixj].y);
	}
	return 0;
}