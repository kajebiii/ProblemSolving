//https://oj.uz/submission/26654

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e3 + 100;

int sign(ll x) { return (x>0) - (x<0); }
struct PT {
	int x, y, c;
	PT() {}
	PT(int xx, int yy, int cc) : x(xx), y(yy), c(cc) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y, 0); }
	ll cross(const PT &o) const { return 1ll * x * o.y - 1ll * y * o.x; }
	ll dot(const PT &o) const { return 1ll * x * o.x + 1ll * y * o.y; }
	int ccw(const PT &o) const { return sign(cross(o)); }
	bool operator<(const PT &o) const {
		if(y != o.y) return y < o.y;
		return x < o.x;
	}
};
vector<PT> Ps;

struct LN {
	PT sl; int p;
	int i, j;
	LN(int ii, int jj) : i(ii), j(jj) {
		sl = Ps[j] - Ps[i];
		if(sl.y > 0 || sl.y == 0 && sl.x > 0) p = 0;
		else p = 1;
	}
	bool operator<(const LN &o) const {
		if(p != o.p) return p < o.p;
		if(sl.ccw(o.sl) != 0) return sl.ccw(o.sl) > 0;
		if(sl.dot(Ps[i]) != sl.dot(Ps[o.i])) return sl.dot(Ps[i]) < sl.dot(Ps[o.i]);
		return sl.dot(Ps[j]) < sl.dot(Ps[o.j]);
	}
};
vector<LN> Ls;

struct IDX {
	int P; vector<ll> l, r, s, m;
	IDX() {}
	IDX(int n) {
		for(P=1; P<n; P<<=1);
		l = r = s = m = vector<ll>(2*P, 0);
	}
	void update(int v, int k) {
		v += P;
		if(k >= 0) l[v] = r[v] = m[v] = s[v] = k;
		else l[v] = r[v] = m[v] = 0, s[v] = k;
		while(v >>= 1) {
			l[v] = max(l[v*2], s[v*2] + l[v*2+1]);
			r[v] = max(r[v*2+1], s[v*2+1] + r[v*2]);
			s[v] = s[v*2] + s[v*2+1];
			m[v] = max(r[v*2] + l[v*2+1], max(m[v*2], m[v*2+1]));
		}
	}
};

int N, Ix[MAX_N];
int main() {
	cin >> N;
	REP(i, N) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		Ps.push_back(PT(x, y, c));
	}
	sort(ALL(Ps));
	REP(i, N) REP(j, N) if(i < j) Ls.push_back(LN(i, j));
	sort(ALL(Ls));
	//	for(LN &l : Ls) printf("[%d %d]\n", l.i, l.j);
	REP(i, N) Ix[i] = i;

	IDX idx = IDX(N);
	REP(i, N) idx.update(i, Ps[i].c);
	ll ans = idx.m[1];
	//	for(int k=0; k<N; k++) printf("[%d %d %d] ", Ps[k].x, Ps[k].y, Ps[k].c); puts("");
	for(int i=0, j=0; i<SZ(Ls); i=j) {
		while(j < SZ(Ls) && Ls[i].sl.ccw(Ls[j].sl) == 0) {
			int &x = Ix[Ls[j].i], &y = Ix[Ls[j].j];
			//			printf("swap %d %d\n", x, y);
			swap(Ps[x], Ps[y]);
			swap(x, y);
			idx.update(x, Ps[x].c);
			idx.update(y, Ps[y].c);
			j++;
		}
		ans = max(ans, idx.m[1]);
		//		for(int k=0; k<N; k++) printf("[%d %d %d] ", Ps[k].x, Ps[k].y, Ps[k].c); puts("");
	}
	printf("%lld\n", ans);
	return 0;
}
