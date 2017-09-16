#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int sign(int x) {return (x>0) - (x<0);}
struct PT {
	int x, y;
	PT() : x(0), y(0) {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y);}
	int cross(const PT &o) const{return x*o.y - y*o.x;}
	int ccw(const PT &o) const{return sign(cross(o));}
}; 

const int debug = 0, fre = 0;
int N;

int main() {
	if(fre) {freopen("input.txt", "r", stdin);}
	int TC; scanf("%d", &TC);
	while(TC--) {
		vector<PT> Ps;
		scanf("%d", &N);
		for(int i=0, x, y; i<N; i++) scanf("%d%d", &x, &y), Ps.emplace_back(x, y);
		for(int i=1; i<N; i++) if(Ps[0].y > Ps[i].y || (Ps[0].y == Ps[i].y && Ps[0].x > Ps[i].x) ) swap(Ps[0], Ps[i]);
		sort(Ps.begin()+1, Ps.end(), [&](const PT &a, const PT &b){
			int val = (a-Ps[0]).ccw(b-Ps[0]);
			if(val > 0) return true; if(val < 0) return false;
			return a.y < b.y;
		});
		vector<PT> Cv;
		for(int i=0; i<N; i++) {
			while(Cv.size() >= 2 && (Cv.back() - Cv[Cv.size()-2]).ccw(Ps[i] - Cv[Cv.size()-2]) <= 0) Cv.pop_back();
			Cv.push_back(Ps[i]);
		}
		if(debug) {for(PT &p : Cv) printf("%d %d\n", p.x, p.y); puts("");}

		//

		N = Cv.size();
		auto next = [&](int x) {return (x+1) % N;};
		auto area = [&](int i, int j, int k) {return (Cv[j]-Cv[i]).cross(Cv[k]-Cv[i]);};
		int ans = 0;
		for(int i=0; i<N; i++) {
			for(int j = next(i), d = i, u = next(i); j != i; j = next(j)) {
				while(area(i, d, j) < area(i, next(d), j)) d = next(d);
				while(area(j, u, i) < area(j, next(u), i)) u = next(u);
				ans = max(ans, area(i, d, j) + area(j, u, i));
				if(debug) printf("[%d %d] [d %d | u %d] [%d + %d] [%d]\n", i, j, d, u, area(i, d, j), area(j, u, i), area(i, d, j) + area(j, u, i));
			}
		}
		printf("%d", ans/2);
		if(ans%2 == 1) printf(".5");
		puts("");
	}
	return 0;
}