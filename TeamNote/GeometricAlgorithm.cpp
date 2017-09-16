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

double EPS = 1e-9, PI = atan2(1, 1) * 4;

int sign(ll v) { return (v>0) - (v<0); }
struct PT {
	int x, y;
	PT() : x(0), y(0) {}
	PT(int xx, int yy) : x(xx), y(yy) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	ll cross(const PT &o) const { return 1ll*x*o.y - 1ll*y*o.x; }
	ll dot(const PT &o) const { return 1ll*x*o.x + 1ll*y*o.y; }
	int ccw(const PT &o) const { return sign(cross(o)); }
	int ccw(const PT &a, const PT &b) const { return (a-*this).ccw(b-*this); }
	ll len2() { return dot(*this); }
	double len() { return sqrt(len2()); }
};


//--double----------------------------------------------------------------

int Dsign(double v) { return (v>EPS) - (v<-EPS); }
struct DPT {
	double x, y;
	DPT() : x(0), y(0) {}
	DPT(double xx, double yy) : x(xx), y(yy) {}
	DPT operator-(const DPT &o) const { return DPT(x-o.x, y-o.y); }
	DPT operator+(const DPT &o) const { return DPT(x+o.x, y+o.y); }
	DPT operator*(const double &d) const { return DPT(x*d, y*d); }
	double cross(const DPT &o) const { return x*o.y - y*o.x; }
	double dot(const DPT &o) const { return x*o.x + y*o.y; }
	int ccw(const DPT &o) const { return Dsign(cross(o)); }
	int ccw(const DPT &a, const DPT &b) const { return (a-*this).ccw(b-*this); }
	double len2() const { return dot(*this); }
	double len() const { return sqrt(len2()); }
	void print(char c = '\n') const { printf("%f %f%c", x, y, c); }
};

vector<DPT> DgetCV(vector<DPT> ps) {
	for(int i=1; i<SZ(ps); i++)
		if(ps[i].y < ps[0].y || abs(ps[i].y - ps[0].y) < EPS && ps[i].x < ps[0].x)
			swap(ps[i], ps[0]);
	sort(ALL(ps), [&](const DPT &a, const DPT &b) {
		int val = ps[0].ccw(a, b);
		if(val == 0) return abs(a.x - ps[0].x) + a.y < abs(b.x - ps[0].x) + b.y;
		return val > 0;
	});
	vector<DPT> res;
	for(int i=0; i<SZ(ps); i++) {
		while(SZ(res) >= 2 && res[SZ(res)-2].ccw(res.back(), ps[i]) <= 0) res.pop_back();
		res.push_back(ps[i]);
	}
	return res;
}
double DgetArea(vector<DPT> ps) {
	vector<DPT> cv = DgetCV(ps);
	double res = 0;
	for(int i=0; i<SZ(cv); i++) res += cv[i].cross(cv[(i+1)%SZ(cv)]);
	return abs(res) / 2;
}
pair<bool, DPT> DgetInter(DPT a, DPT b, DPT c, DPT d) {
	double all = (b-a).cross(d-c);
	if(abs(all) < EPS) return make_pair(false, DPT());
	double at = (c-a).cross(d-c) / all;
	double ct = (c-a).cross(b-a) / all;
	//	something
	//	if(at > 1 - EPS && ct > -EPS && ct < 1+EPS)
	//		return make_pair(true, DPT(c + (d-c) * ct));
	//	return make_pair(false, DPT());
}

int main() {
	return 0;
}