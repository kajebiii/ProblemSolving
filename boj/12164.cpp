#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 3e3 + 10;
typedef long long ll;

int sign(ll x) {return (x>0) - (x<0); }
struct PT {
	int x, y;
	PT() : x(0), y(0) {} 
	PT(int x_, int y_) : x(x_), y(y_){} 
	
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y);}
	
	ll cross(const PT &o) const { return 1ll*x*o.y - 1ll*y*o.x; }
	ll cross(const PT &b, const PT &c) const { return (b-*this).cross(c-*this); }
	int ccw(const PT &o) const { return sign(cross(o)); }
	int ccw(const PT &b, const PT &c) const { return sign(cross(b, c)); }
	int type() const {
		if(y == 0 && x > 0) return 0;
		if(y > 0) return 1;
		if(y == 0 && x <= 0) return 2;
		return 3; // y < 0;
	}
	ll size() const {return 1ll*x*x < 1ll*y*y;}
};

int N;

int main() {
	if(0) {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d", &N);
		vector<PT> Ps; vector<int> cv;
		for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Ps.emplace_back(x, y);

		printf("Case #%d: \n", tc);
		for(int o=0; o<N; o++) {
			vector<PT> list;
			for(int i=0; i<N; i++) if(i != o) list.push_back(Ps[i] - Ps[o]);
			sort(list.begin(), list.end(), [&](const PT &a, const PT &b) {
				int ta = a.type(), tb = b.type();
				if(ta != tb) return ta < tb;
				int val = PT().ccw(a, b);
				if(val == 0) val = -1;
				return val == 1 ? true : false;
			});
			
			int all = list.size(), ans = all;
			for(int i=0, j=0; i<all; i++) {
				while(j+1 < i+all && list[i].ccw(PT(), list[(j+1)%all]) <= 0) j = j+1;
				ans = min(ans, all - (j-i+1));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}