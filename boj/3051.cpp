#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<double, double> pd;
struct PT
{
	int x, y;
	PT() : x(0), y(0) {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	bool operator<(PT &o)
	{
		if(o.x == x) return y < o.y;
		return x < o.x;
	}
	pd getpd()
	{
		return make_pair((double)x, (double)y);
	}
};
struct LINE
{
	PT s, e;
	LINE(PT s_, PT e_) : s(PT(s_.x, s_.y)), e(PT(e_.x, e_.y)) {}
	LINE() : s(PT(0, 0)), e(PT(0, 0)) {}
};

int ccw(PT &a, PT &b, PT &c)
{
	ll val = 1ll*(b.x-a.x)*(c.y-a.y) - 1ll*(b.y-a.y)*(c.x-a.x);
	if(val > 0) return 1;
	if(val < 0) return -1;
	return 0;
}

int isCross(LINE &a, LINE &b)
{
	int aab[2] = {ccw(a.s, a.e, b.s), ccw(a.s, a.e, b.e)};
	int bba[2] = {ccw(b.s, b.e, a.s), ccw(b.s, b.e, a.e)};
	int byA = aab[0] * aab[1];
	int byB = bba[0] * bba[1];
	int sum = 0; for(int i=0; i<2; i++) sum += (abs(aab[i]) + abs(bba[i]));
	if(sum == 0)
	{
		if(a.e < a.s) swap(a.s, a.e);
		if(b.e < b.s) swap(b.s, b.e);
		if(a.e < b.s || b.e < a.s) return 0;
		return 2;
	}
	return byA <= 0 && byB <= 0 ? 1 : 0;
}
LINE mergeLine(LINE &a, LINE &b)
{
	if(a.e < a.s) swap(a.s, a.e);
	if(b.e < b.s) swap(b.s, b.e);
	PT getMxMn[4] = {a.s, a.e, b.s, b.e};
	sort(getMxMn, getMxMn + 4);
	return LINE(getMxMn[0], getMxMn[3]);
}
pd getPT(LINE &a, LINE &b)
{
	if(ccw(b.s, b.e, a.s) == 0) return a.s.getpd();
	if(ccw(b.s, b.e, a.e) == 0) return a.e.getpd();
	if(ccw(b.s, b.e, a.s) == 1) swap(a.s, a.e);
	pd result;
	int cnt = 0;
	for(pd l = a.s.getpd(), r = a.e.getpd(); cnt<40; cnt++)
	{
		pd m = make_pair((l.first + r.first) / 2, (l.second + r.second) / 2);
		double val = 1.0*(b.e.x-b.s.x)*(m.second-b.s.y) - 1.0*(b.e.y-b.s.y)*(m.first-b.s.x);
		if(val > 0) r = m;
		else l = m;
		result = m;
	}
	return result;
}
bool isDiff(double x, double y)
{
	double diff = abs(x - y);
	return diff > 1e-9;
}
bool isDiff(pd x, pd y)
{
	return isDiff(x.first, y.first) || isDiff(x.second, y.second);
}

const int MAX_N = 22;

int N; vector<LINE> L;
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		PT a, b;
		scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
		LINE now = LINE(a, b);
		L.push_back(now);
	}

	for(bool changed = true; changed; )
	{
		changed = false;
		for(int i=0; i<L.size() && !changed; i++) for(int j=i+1; j<L.size(); j++)
			if(isCross(L[i], L[j]) == 2)
			{
				L[i] = mergeLine(L[i], L[j]);
				L.erase(L.begin() + j);
				changed = true;
				break;
			}
	}
	int n = L.size(), ans = 0;
	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++)
		if(isCross(L[i], L[j]) == 1 && isCross(L[j], L[k]) == 1 && isCross(L[k], L[i]) == 1)
		{
			pd t1 = getPT(L[i], L[j]), t2 = getPT(L[j], L[k]);
			if(isDiff(getPT(L[i], L[j]), getPT(L[j], L[k])))
				ans++;
		}
	printf("%d\n", ans);

	return 0;
}
