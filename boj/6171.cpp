#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 5e4 + 100;
typedef long long ll;

struct PT{ll x, y; PT(){} PT(ll x_, ll y_) : x(x_), y(y_) {} };
//when PT doesn't use as PT, x is slope and y is y-intercept
int N; PT P[MAX_N];
ll Dy[MAX_N];
vector<PT> CV;
ll calc(int ix, ll x) {
	ll yc = CV[ix].y, l = CV[ix].x;
	return yc + l * x;
}
double cross(PT a, PT b) {
	return (double)(b.y - a.y) / (a.x - b.x);
}

int main() {
	scanf("%d", &N);
	for(ll i=0, x, y; i<N; i++) scanf("%lld%lld", &x, &y), P[i] = PT(x, y);
	sort(P, P+N, [&](const PT &a, const PT &b) {
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	vector<PT> Ps;
	for(int i=0; i<N; i++) {
		while(Ps.empty() == false && Ps.back().y <= P[i].y)
			Ps.pop_back();
		Ps.push_back(P[i]);
	}
	N = Ps.size(); int ix = 0;
	for(int i=0; i<N; i++) {
		ll yc = (i>0?Dy[i-1]:0), l = Ps[i].y;
		while(CV.size() >= 2 && cross(CV[CV.size()-2], CV.back()) >= cross(CV.back(), PT(l, yc)) )
			CV.pop_back();
		CV.emplace_back(l, yc);
		while(ix+1 < CV.size() && calc(ix, Ps[i].x) >= calc(ix+1, Ps[i].x)) ix++;
		Dy[i] = calc(ix, Ps[i].x);
	}
	printf("%lld\n", Dy[N-1]);
	return 0;
}