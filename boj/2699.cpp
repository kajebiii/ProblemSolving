#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long ll;

struct PT
{
	int x, y;
	PT(int x_, int y_) : x(x_), y(y_) {}
};

int ccw(PT &a, PT &b, PT &c)
{
	ll x[2] = {b.x - a.x, c.x - a.x};
	ll y[2] = {b.y - a.y, c.y - a.y};
	ll val = x[0] * y[1] - x[1] * y[0];
	if(val == 0) return 0;
	return val / abs(val);
}
ll diff(PT &a, PT &b)
{
	ll dx = b.x - a.x;
	ll dy = b.y - a.y;
	return abs(dx) + abs(dy);
}
vector<PT> Ps;
int N;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		Ps.clear();
		PT dl = PT(-1, -1);
		for(int i=0; i<N; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			Ps.push_back(PT(x, -y));
			if(i == 0 || dl.y > Ps.back().y || (dl.y == Ps.back().y && dl.x > Ps.back().x) )
				dl = Ps.back();
		}
		sort(Ps.begin(), Ps.end(), [&](PT &a, PT &b)
		{
			int val = ccw(dl, a, b);
			if(val > 0) return true;
			if(val < 0) return false;
			return diff(dl, a) < diff(dl, b);
		});

		vector<PT> Ans;
		for(int i=0; i<min((int)Ps.size(), 2); i++) Ans.push_back(Ps[i]);

		int ix = Ans.size();
		for(int i=2; i<(int)Ps.size(); i++)
		{
			while(ix >= 2 && ccw(Ans[ix-2], Ans[ix-1], Ps[i]) <= 0) Ans.pop_back(), ix--;
			Ans.push_back(Ps[i]), ix++;
		}
		printf("%d\n", (int)Ans.size());
		for(PT &t : Ans)
			printf("%d %d\n", t.x, -t.y);
	}
	return 0;
}