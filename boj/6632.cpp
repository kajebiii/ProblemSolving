#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;
typedef pair<double, int> pdi;

int gsign(int x) { return (x > 0) - (x < 0); }
struct PT {
	int x, y;
	PT() : x(0), y(0) {}
	PT(int a, int b) : x(a), y(b) {}
	bool operator<(const PT &o) const {
		if(x != o.x) return x < o.x;
		return y < o.y;
	}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	PT operator+(const PT &o) const { return PT(x+o.x, y+o.y); }
	PT operator*(const int &d) const { return PT(x*d, y*d);}
	int gcross(const PT &o) const { return x*o.y - y*o.x;}
	int gccw(const PT &o) const { return gsign(gcross(o)); }
};
const int MAX_N = 1e2 + 10, MAX_L = 222;
const double EPS = 1e-7;

int N; PT P[MAX_N];
double ginter(PT a0, PT a1, PT b0, PT b1) {
	int all = (a1 - a0).gcross(b1 - b0);
	if(all == 0) return -1e9;
	int at = (b0 - a0).gcross(b1 - b0);
	int bt = (b0 - a0).gcross(a1 - a0);
	if(all < 0) {all *= -1, at *= -1, bt *= -1;}
	if(at < 0 || bt < 0 || at > all || bt > all) return -1e9;
	return a0.x + (double)(a1.x - a0.x) * at / all;
}

int main() {
	while(scanf("%d", &N) == 1) {
		if(N == 0) break;
		for(int i=0, x, y; i<N; i++) {
			scanf("%d%d", &x, &y);
			P[i] = PT(x + 110, y * 2);
		}
		P[N] = P[0];
		int ans = 0;
		for(int j= -110 * 2; j<=110 * 2; j+=2) {
			int chk = j + 1;
			PT l = PT(-10, chk), r = PT(220, chk);
			PT ul = PT(-10, chk+1), ur = PT(220, chk+1);
			PT dl = PT(-10, chk-1), dr = PT(220, chk-1);
			vector<pdi> list;
			for(int i=0; i<N; i++) {
				double inter = ginter(l, r, P[i], P[i+1]);
				if(inter < -1e8) continue;
				list.emplace_back(inter, i);
			}
			sort(list.begin(), list.end());
			assert(list.size() % 2 == 0);
			for(int i=0; i<list.size(); i+=2) {
				int lix = list[i].second, rix = list[i+1].second;
				double lx = max(ginter(ul, ur, P[lix], P[lix+1]), ginter(dl, dr, P[lix], P[lix+1])) - EPS;
				double rx = min(ginter(ul, ur, P[rix], P[rix+1]), ginter(dl, dr, P[rix], P[rix+1])) + EPS;

				if((int)lx + 1 <= (int)rx)
					ans += (int)rx - (int)lx - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}