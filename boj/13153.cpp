#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;

struct PT {
	int x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const {return PT(x-o.x, y-o.y);}
	double len() const {return sqrt(1ll*x*x + 1ll*y*y);}
};

int main() {
	vector<PT> Ps = vector<PT>(3);
	for(int i=0; i<3; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Ps[i] = PT(x, y);
	}
	double l[3];
	for(int i=0; i<3; i++) l[i] = (Ps[(i+1)%3] - Ps[i]).len();

	double inP = (l[0] * l[0] + l[1] * l[1] - l[2] * l[2]);
	double A = 1. / 4 * sqrt(4 * l[0] * l[0] * l[1] * l[1] -  inP * inP);

	double reR = A * 2 / (l[0] + l[1] + l[2]), r;
	scanf("%lf", &r);
	printf("%f\n", (reR-r)/r*100);
	return 0;
}