#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

const double INF = 1e20;

struct PP {
	int x, v, ix;
	PP() {}
	PP(int x_, int v_, int i_) : x(x_), v(v_), ix(i_) {}
	double pos(double t) {return x + t * v;}
};

const int MAX_N = 5e2 + 1;

int N, V;
double solve() {
	scanf("%d%d", &V, &N);
	vector<int> Xs, Vs; Xs = Vs = vector<int>(N, 0);
	for(int i=0; i<N; i++) scanf("%d", &Xs[i]);
	for(int i=0; i<N; i++) scanf("%d", &Vs[i]);
	vector<PP> Pl, Pr, Ps;
	for(int i=0; i<N; i++) {
		PP now = PP(Xs[i], Vs[i], i);
		if(Xs[i] < 0) now.v *= -1;
		if(Xs[i] < 0) Pl.push_back(now); else Pr.push_back(now);
		Ps.push_back(now);
	}
	sort(Pl.begin(), Pl.end(), [&](const PP &a, const PP &b) {return abs(a.v) > abs(b.v);});
	sort(Pr.begin(), Pr.end(), [&](const PP &a, const PP &b) {return abs(a.v) > abs(b.v);});
	for(auto it = Pl.begin(); it != Pl.end(); ) {
		bool findJ = false;
		for(auto jt = Pl.begin(); jt != Pl.end(); jt++) {
			PP ix = *it, jx = *jt;
			if(abs(ix.x) < abs(jx.x) && abs(ix.v) < abs(jx.v)) { findJ = true; break; }
		}
		if(findJ) it = Pl.erase(it); else it++;
	}
	for(auto it = Pr.begin(); it != Pr.end(); ) {
		bool findJ = false;
		for(auto jt = Pr.begin(); jt != Pr.end(); jt++) {
			PP ix = *it, jx = *jt;
			if(abs(ix.x) < abs(jx.x) && abs(ix.v) < abs(jx.v)) { findJ = true; break; }
		}
		if(findJ) it = Pr.erase(it); else it++;
	}
	int L = Pl.size(), R = Pr.size();
	vector< vector< vector<double> > > Dy = 
		vector< vector< vector<double> > >(L+1, vector< vector<double> >(R+1, vector<double>(N, INF)));
	rep(i, N) Dy[0][0][i] = (double)abs(Ps[i].x) / (V - abs(Ps[i].v));
	rep(i, L+1) rep(j, R+1) rep(k, N) {
		if(Dy[i][j][k] > INF / 2) continue;
		double t = Dy[i][j][k], x = Ps[k].pos(t);
		if(i != L) { // k -> i
			int ix = Pl[i].ix;
			double nx = Ps[ix].pos(t), nv = abs(Ps[ix].v);
			if(nx < x)
				Dy[i+1][j][ix] = min(Dy[i+1][j][ix], t + (double)abs(nx-x) / (V - nv));
			else
				Dy[i+1][j][k] = min(Dy[i+1][j][k], t);
		}
		if(j != R) { // k -> j
			int ix = Pr[j].ix;
			double nx = Ps[ix].pos(t), nv = abs(Ps[ix].v);
			if(x < nx)
				Dy[i][j+1][ix] = min(Dy[i][j+1][ix], t + (double)abs(nx-x) / (V - nv));
			else
				Dy[i][j+1][k] = min(Dy[i][j+1][k], t);
		}
	}
	double ans = INF;
	rep(k, N) ans = min(ans, Dy[L][R][k]);
	return ans;
}

const int fre = 0;
int main() {
	if(fre) freopen("input.txt", "r", stdin);
	if(fre) freopen("output.txt", "w", stdout);

	int TC; scanf("%d", &TC);
	for(int tc=1; tc<=TC; tc++)
		printf("Case #%d: %.9f\n", tc, solve());
	return 0;
}