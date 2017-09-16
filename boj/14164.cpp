#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <assert.h>

using namespace std;
typedef long long ll;

int sign(ll x) { return (x > 0) - (x < 0); }
struct PT {
	int x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	ll cross(const PT &o) const { return 1ll * x * o.y - 1ll * y * o.x; }
	ll cross(const PT &a, const PT &b) const { return (a - (*this)).cross(b - (*this)); }
	int ccw(const PT &o) const { return sign(cross(o)); }
	int ccw(const PT &a, const PT &b) const { return sign(cross(a, b)); }
	bool operator<(const PT &o) { return (x != o.x ? x < o.x : y < o.y); }
};

const int MAX_N = 3e2 + 10;

int N; vector<PT> Ps;
int Below[MAX_N][MAX_N];

const int fre = 0;
int main() {
	if(fre) freopen("triangles.in", "r", stdin);
	if(fre) freopen("triangles.out", "w", stdout);

	scanf("%d", &N);
	for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Ps.emplace_back(x, y);

	function<void(int, int)> calcBelow = [&](int a, int b) {
		if(Ps[b] < Ps[a]) return calcBelow(b, a);
		PT l = PT(Ps[a].x, -1), r = PT(Ps[b].x, 1e6 + 1);
		for(int i=0; i<N; i++) if(l < Ps[i] && Ps[i] < r && Ps[a].ccw(Ps[b], Ps[i]) < 0) { // not include endpoints
			Below[a][b] += 2;
			if(Ps[i].x == Ps[a].x || Ps[i].x == Ps[b].x) Below[a][b]--;
		}
		Below[b][a] = -Below[a][b];
	};
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) calcBelow(i, j);
//	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) printf("[%d %d] [%d %d] : %d\n", Ps[i].x, Ps[i].y, Ps[j].x, Ps[j].y, Below[i][j]);

	vector<int> Ans = vector<int>(N-2, 0);
	auto isBelow = [&](int k, int i, int j) {
		if(Ps[j] < Ps[i]) swap(i, j);
		return Ps[k].x > Ps[i].x && Ps[k].x < Ps[j].x && Ps[i].ccw(Ps[j], Ps[k]) < 0;
	};
	for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) for(int k=j+1; k<N; k++) {
		int sum = abs(Below[i][j] + Below[j][k] + Below[k][i]) / 2;
		sum -= isBelow(i, j, k);
		sum -= isBelow(j, k, i); 
		sum -= isBelow(k, i, j);
		assert(sum >= 0);
		Ans[sum]++;
	}
	for(int val : Ans) printf("%d\n", val);
	return 0;
}