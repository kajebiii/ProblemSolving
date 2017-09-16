#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <assert.h>

using namespace std;

const double EPS = 1e-7;
const int debug = 0;

int gsign(double x) {
	if(abs(x) < EPS) return 0;
	return (x > 0) - (x < 0);
}
struct PT {
	double x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT(double x_, double y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	PT operator+(const PT &o) const { return PT(x+o.x, y+o.y); }
	PT operator*(const double &d) const { return PT(x*d, y*d); }
	PT operator/(const double &d) const { return PT(x/d, y/d); }
	double gcross(const PT &o) const { return x*o.y - y*o.x;}
	double gdot(const PT &o) const { return x*o.x + y*o.y;}
	double gdis() const { return sqrt(x*x + y*y);}
	int gccw(const PT &o) const{return gsign(gcross(o));}
	bool operator<(const PT &o) const {
		if(x != o.x) return x < o.x;
		return y < o.y;
	}
};
struct LINE {
	PT p[2];
	vector<int> list;
	PT d;
	LINE(PT a, PT b) {
		p[0] = a, p[1] = b;
		d = PT(b.x - a.x, b.y - a.y);
	}
};
 
const int MAX_P = 1e4 + 10, MAX_N = 1e2 + 10;

PT ginter(const LINE &a, const LINE &b) {
	double all = (a.p[1] - a.p[0]).gcross(b.p[1] - b.p[0]);
	double t0 = (b.p[0] - a.p[0]).gcross(b.p[1] - b.p[0]) / all;
	double t1 = (b.p[0] - a.p[0]).gcross(a.p[1] - a.p[0]) / all;
	if(t0 >= -EPS && t1 >= -EPS && t0 <= 1 + EPS && t1 <= 1 + EPS)
		return a.p[0] + (a.p[1] - a.p[0]) * t0;
	return PT(-1e9, -1e9);
}

vector<LINE> Ls;
bool isWell(int a, int am, int b, int bm) {
	PT ad = Ls[a].d * am, bd = Ls[b].d * bm;
	return ad.gdot(bd) >= -EPS;
}
map<PT, int> Ps; int PN;
PT toP[MAX_P];
vector<int> isOn[MAX_P];
bool Chk[MAX_N][MAX_P], Vis[MAX_N][MAX_P][2];
int Ix[MAX_N][MAX_P];
double Dis[MAX_N][MAX_P][2];
int N;

typedef pair<double, PT> pdp;
struct NODE {
	double dis;
	int l, p, to;
	NODE() {}
	NODE(double d_, int l_, int p_, int t_) : dis(d_), l(l_), p(p_), to(t_) {};
	bool operator<(const NODE &o) const {return dis > o.dis;}
};

double getDis() {
	int lastP = Ps[Ls[N-1].p[1]];

	for(int i=0; i<N; i++) for(int p : Ls[i].list) for(int j=0; j<2; j++)
		Vis[i][p][j] = false, Dis[i][p][j] = 1e9;

	priority_queue<NODE> Q; 
	int sp = Ps[Ls[0].p[0]];
	Q.push(NODE(0, 0, Ps[Ls[0].p[0]], 1));
	Dis[0][sp][1] = 0;
	while(!Q.empty()) {
		NODE t = Q.top();
		double nd = t.dis;
		int l = t.l, p = t.p, to = t.to; Q.pop();

		if(Vis[l][p][(to+1)/2] == true) continue;
		Vis[l][p][(to+1)/2] = true;
		if(p == lastP) {
			if(isWell(l, to, N-1, 1)) return Dis[l][p][(to+1)/2];
		}

		for(int nl : isOn[p]) {
			int ix = Ix[nl][p];
			for(int pi = -1; pi <= 1; pi+=2) {
				int nx = ix + pi;
				if(nx < 0 || nx >= Ls[nl].list.size()) continue;
				int np = Ls[nl].list[nx];
				double plusD = (toP[np] - toP[p]).gdis();

				if(isWell(l, to, nl, pi) == false) continue;
				if(Vis[nl][np][(pi+1)/2] == true) continue;
				if(Dis[nl][np][(pi+1)/2] > Dis[l][p][(to+1)/2] + plusD) {
					Dis[nl][np][(pi+1)/2] = Dis[l][p][(to+1)/2] + plusD;
					Q.push(NODE(Dis[nl][np][(pi+1)/2], nl, np, pi));
				}
			}
		}
	}
	return 1e9;
}

int main() {
	while(scanf("%d", &N) == 1) {
		if(N == 0) break;
		if(debug) printf("[]\n");
		for(int i=0; i<N; i++) {
			int x, y, a, b; scanf("%d%d%d%d", &x, &y, &a, &b);
			Ls.push_back(LINE(PT(x, y), PT(a, b)));
		}

		auto pushP = [&](PT p, int ix) {
			if(p.x < -1e8) return;
			if(Ps.count(p) == 0) {
				if(debug) printf("%f %f | insert\n", p.x, p.y);
				toP[PN] = p;
				Ps[p] = PN++;
			}
			int val = Ps[p];
			if(Chk[ix][val] == true) return;
			isOn[val].push_back(ix);
			Ls[ix].list.push_back(val);
			Chk[ix][val] = true;
		};
		for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
			PT inter = ginter(Ls[i], Ls[j]);
			pushP(inter, i);
			pushP(inter, j);
		}
		for(int i=0; i<N; i++) {
			pushP(Ls[i].p[0], i);
			pushP(Ls[i].p[1], i);
			sort(Ls[i].list.begin(), Ls[i].list.end(), [&](const int &a, const int &b) {
				return toP[a] < toP[b];
			});
			if(Ls[i].list[0] != Ps[Ls[i].p[0]])
				reverse(Ls[i].list.begin(), Ls[i].list.end());
			int cnt = 0;
			for(int p : Ls[i].list)
				Ix[i][p] = cnt++;
			for(int p : Ls[i].list) 
				if(debug)
					printf("[%d] %f %f\n", i, toP[p].x, toP[p].y);
		}

		double ans = getDis();
		if(ans > 1e8) puts("unreachable");
		else printf("%.03f\n", ans);

		for(int i=0; i<PN; i++) {
			isOn[i].clear();
			isOn[i].shrink_to_fit();
		}
		for(int i=0; i<N; i++) {
			for(int p : Ls[i].list)
				Chk[i][p] = false;
		}
		Ls.clear(); Ls.shrink_to_fit();
		Ps.clear();
		PN = 0;
	}
	return 0;
}