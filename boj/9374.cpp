#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

const double PI = atan(1) * 4, EPS = 1e-7;

struct PT {
	double x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT(double x_, double y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	PT operator+(const PT &o) const { return PT(x+o.x, y+o.y); }
	PT operator*(const double &d) const { return PT(x*d, y*d); }
	PT rotate(const double &th) const{return PT(x*cos(th)-y*sin(th), x*sin(th)+y*cos(th));} // counterclockwise
	double size() {return sqrt(x*x + y*y);}
	double cross(const PT &o) const{return x*o.y - y*o.x;}
};
PT inter(const PT &a, const PT &b, const PT &c, const PT &d) {
	double all = (b-a).cross(d-c);
	double ab = (c-a).cross(d-c) / all;
	double cd = (c-a).cross(b-a) / all;
	if(ab < -EPS || cd < -EPS) return PT(-1e9, -1e9);
	if(ab > 1+EPS || cd > 1+EPS) return PT(-1e9, -1e9);
	return a + (b-a) * ab;
}

int N;
int main() {
	int TC; scanf("%d", &TC);
	while(TC--) {
		vector<PT> Ps;
		scanf("%d", &N);
		for(int i=0, x, y; i<N; i++) {
			scanf("%d%d", &x, &y);
			Ps.emplace_back(x, y);
		}
		Ps.push_back(Ps[0]);
		PT d = Ps[1] - Ps[0]; d = d * (1.0 / d.size());
		PT p = (Ps[1] + Ps[0]) * (0.5);
		PT d45 = d.rotate(PI * 45 / 180) * 20000.0;
		PT d135 = d.rotate(PI * 135 / 180) * 20000.0;

		vector<PT> list; list.push_back(p);
		bool cr = false;
		for(int i=1; i<N; i++) {
			if(cr == false) {
				PT interP = inter(p, p + d45, Ps[i], Ps[i+1]);
				if(interP.x < -1e8) continue;
				cr = true;
				list.push_back(interP);

				//chk two inter in one line
				interP = inter(p, p + d135, Ps[i], Ps[i+1]);
				if(interP.x < -1e8) continue;
				list.push_back(interP);
				break;
			} else {
				list.push_back(Ps[i]);
				PT interP = inter(p, p + d135, Ps[i], Ps[i+1]);
				if(interP.x < -1e8) continue;
				list.push_back(interP);
				break;
			}
		}

		double ans = 0, all = 0;
		for(int i=0; i<N; i++) all += Ps[i].cross(Ps[i+1]);
		int nN = list.size(); list.push_back(list[0]);
		for(int i=0; i<nN; i++) ans += list[i].cross(list[i+1]);
		ans = abs(ans); all = abs(all);
		printf("%.10f\n", ans/all);
	}
	return 0;
}