#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <queue>

using namespace std;

const int MAX_N = 4e2 + 10;
const double EPS = 1e-7;

int sign(double x) {
	if(abs(x) < EPS) return 0;
	return (x > 0) - (x < 0);
}
struct PT {
	double x, y;
	PT() {} PT(double x_, double y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const { return PT(x - o.x, y - o.y); }
	double cross(const PT &o) const { return x * o.y - y * o.x; }
	double cross(const PT &a, const PT &b) const { return (a-*this).cross(b-*this); }
	double ccw(const PT &o) const { return sign(cross(o)); }
	double ccw(const PT &a, const PT &b) const { return sign(cross(a, b)); }
};
bool cross(PT &a, PT &b, PT &c, PT &d) {
	double all = (b-a).cross(d-c);
	if(abs(all) < EPS) return false;
	double at = (c-a).cross(b-a) / all;
	double ct = (c-a).cross(d-c) / all;
	return (at > -EPS && at < 1+EPS && ct > -EPS && ct < 1+EPS);
}

int L, W, N;
double X, Y, Le;
bool Chk[MAX_N][MAX_N];

int main() {
//	freopen("input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--) {
		scanf("%d%d", &L, &W);
		scanf("%lf%lf%lf", &X, &Y, &Le);

		vector<PT> R; R.emplace_back(X, Y); R.emplace_back(X, Y+Le); R.emplace_back(X+Le, Y+Le); R.emplace_back(X+Le, Y); R.emplace_back(X, Y);
		vector<PT> Ps;
		for(int i=0; i<=W; i++) Ps.emplace_back((double)0, (double)i), Ps.emplace_back((double)L, (double)i);
		for(int i=1; i< L; i++) Ps.emplace_back((double)i, (double)0), Ps.emplace_back((double)i, (double)W);
		int N = Ps.size();

		for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
			bool isCross = false;
			for(int k=0; k<4; k++) if(cross(Ps[i], Ps[j], R[k], R[k+1])) {
//				printf("%lf %lf | %lf %lf || %lf %lf | %lf %lf = %d\n", Ps[i].x, Ps[i].y, Ps[j].x, Ps[j].y, R[k].x, R[k].y, R[k+1].x, R[k+1].y, 1);
				isCross = true; break;
			}
			Chk[i][j] = !isCross;
		}
		int ans = 0;
		for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) for(int k=j+1; k<N; k++)
			if(Chk[i][j] & Chk[j][k] & Chk[i][k])
				if(Ps[i].ccw(Ps[j], Ps[k]) != 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}