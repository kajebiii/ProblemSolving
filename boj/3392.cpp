#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e4 + 100;

vector<int> Ys;
struct ST
{
	int x, y;
	int cnt, val;
	ST *l, *r;
	ST(int a, int b)
	{
		x = a; y = b; 
		cnt = val = 0;
		if(x != y)
		{
			int m = (x+y) >> 1;
			l = new ST(x, m);
			r = new ST(m+1, y);
		}
	}
	void update(int a, int b, int plus)
	{
		if(y < a || b < x) return; 
		if(a <= x && y <= b)
		{
			cnt += plus;
		}
		else if(x != y)
		{
			l -> update(a, b, plus);
			r -> update(a, b, plus);
		}
		if(cnt > 0) val = Ys[y+1] - Ys[x];
		else
		{
			val = 0;
			if(x != y) val = l -> val + r -> val;
		}
	}
}*Root;
struct LINE
{
	int x, lo, hi, plus;
	LINE(){}
	LINE(int a, int b, int c, int d):x(a),lo(b),hi(c),plus(d){}
	const bool operator<(const LINE &o) const
	{
		return x < o.x;
	}
}L[MAX_N * 2];

int N;
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int x0, y0, x1, y1;
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		L[i*2+0] = LINE(x0, y0, y1, +1);
		L[i*2+1] = LINE(x1, y0, y1, -1);
		Ys.push_back(y0); Ys.push_back(y1);
	}
	sort(Ys.begin(), Ys.end());
	Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());
	Root = new ST(0, Ys.size() - 1);

	sort(L, L+N*2);

	for(int i=0; i<2*N; i++)
	{
		L[i].lo = lower_bound(Ys.begin(), Ys.end(), L[i].lo) - Ys.begin();
		L[i].hi = lower_bound(Ys.begin(), Ys.end(), L[i].hi) - Ys.begin();
	}
	int ans = 0;
	for(int i=0; i<2*N; i++)
	{
		if(i != 0) 
			ans += (L[i].x - L[i-1].x) * (Root -> val);
		Root -> update(L[i].lo, L[i].hi - 1, L[i].plus);
	}
	printf("%d\n", ans);
	return 0;
}