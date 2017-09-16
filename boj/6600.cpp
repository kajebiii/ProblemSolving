#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct PT {
	double x, y;
	PT() {}
	PT(double x_, double y_) : x(x_), y(y_) {}
	double dot(const PT &o) const{return x*o.x + y*o.y;}
	double len() const{return sqrt(dot(*this));}
	double cross(const PT &o) const{return x*o.y - y*o.x;}
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y); }
};

int main() {
	PT Ps[3];
	double pi = atan(1) * 4;
	while(scanf("%lf%lf%lf%lf%lf%lf", &Ps[0].x, &Ps[0].y, &Ps[1].x, &Ps[1].y, &Ps[2].x, &Ps[2].y) == 6) {
		double R = 1;
		for(int k=0; k<3; k++)
			R *= (Ps[(k+1)%3] - Ps[k]).len();
		R /= 2;
		R /= abs((Ps[1] -  Ps[0]).cross(Ps[2] - Ps[0]));
		printf("%.2f\n", R * 2 * pi);
	}
	return 0;
}