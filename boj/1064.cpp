#include <stdio.h>
#include <algorithm>

using namespace std;

struct PT
{
	int x, y;
	PT() {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const{return PT(x-o.x, y-o.y); }
	int gccw(const PT &o) const
	{
		int val = x * o.y - y * o.x;
		return (val > 0) - (val < 0);
	}
	double size() {return sqrt(x*x+y*y); }
};

PT P[3];
int main()
{
	for(int i=0; i<3; i++) scanf("%d%d", &P[i].x, &P[i].y);
	P[1] = P[1] - P[0];
	P[2] = P[2] - P[0];
	if(P[1].gccw(P[2]) == 0) puts("-1");
	else
	{
		P[0] = P[1] - P[2];
		double d[3], sum = 0;
		for(int i=0; i<3; i++) d[i] = P[i].size(), sum += d[i];
		printf("%.20lf\n", 2.0 * (max(d[0], max(d[1], d[2])) - min(d[0], min(d[1], d[2])) ) );
	}
	return 0;
}