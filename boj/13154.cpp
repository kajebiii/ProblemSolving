#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

struct PT {
	double x, y, z;
	PT() {}
	PT(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y, z-o.z); }
	PT operator*(const double &o) const { return PT(x*o, y*o, z*o); }
	double dot(const PT &o) const {return x*o.x+y*o.y+z*o.z;}
	PT cross(const PT &o) const {return PT(y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x);}
	double len() const{return sqrt(x*x+y*y+z*z);}
	PT norm() const{return PT(x/len(), y/len(), z/len());}
};

const int MAX_N = 1e4 + 10;

int N; double D;
PT P[2], S, V, Normal;

void getInput(PT &pt) {
	double x, y, z; scanf("%lf%lf%lf", &x, &y, &z);
	pt = PT(x, y, z);
}
int main() {
	scanf("%d", &N); scanf("%lf", &D);
	for(int i=0; i<2; i++) getInput(P[i]), P[i] = P[i].norm();
	Normal = P[0].cross(P[1]);

	int ans = 0;
	for(int i=0; i<N; i++)  {
		getInput(S), getInput(V);
		S = S - V * D;
		if(abs(S.len() - D) > 5e-2) continue;
		double val = S.dot(Normal);
		if(abs(val) < 1e-2) ans++;
	}
	printf("%d\n", ans);
	return 0;
}