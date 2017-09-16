#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 10, ITER = 200;

typedef pair<double, double> pd;

struct PT
{
	double x, y;
	PT() : x(0), y(0) {}
	PT(double x_, double y_) : x(x_), y(y_) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	PT operator*(const PT &o) const { return PT(x+o.x, y+o.y); }
	double size() const{ return sqrt(x*x + y*y); }
	PT rotate(const PT &o) const{return PT(o.y - y, x);}
}S, E, A, B, St[MAX_N];

int v_w, v_b, N;
double getT(const PT &a, const PT &b, int v) {return (a-b).size()/v;}
void init()
{
	scanf("%d%d", &v_w, &v_b);
	scanf("%lf%lf%lf%lf", &S.x, &S.y, &E.x, &E.y);
	scanf("%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y);
	scanf("%d", &N);
	E = E - S; A = A - S; B = B - S;
	for(int i=1; i<=N; i++)
	{
		scanf("%lf%lf", &St[i].x, &St[i].y);
		St[i] = St[i] - S;
	}
}

double getT(double x1, double x2, double H, double y)
{
	double o0 = sqrt(x1*x1+(H-y)*(H-y)) / v_w;
	double o1 = sqrt(x2*x2+( +y)*( +y)) / v_b;
	return o0 + o1;
}
pd getOp(double x1, double x2, double H) // x1 use v_w, x2 use v_b => (time, y)
{
	double res = -1, val = -1; int cnt = 0;
	for(double l=0, r=H; cnt<ITER; cnt++)
	{
		double m[2] = {(l*2+r)/3, (l+2*r)/3};
		double ll = getT(x1, x2, H, m[0]);
		double rr = getT(x1, x2, H, m[1]);
		if(ll < rr) r = m[1]; else l = m[0];
		res = l; val = ll;
	}
	return make_pair(val, res);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	init();

	double Ans = (A-B).size() / v_w;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		Ans = min(Ans, getT(A, St[i], v_w) +  getT(St[i], St[j], v_b) +  getT(St[j], B, v_w));

	for(int t=1; t<=8; t++)
	{
//		printf("%d : %lf %lf | %lf %lf\n", t, A.x, A.y, B.x, B.y);
		//do
		for(int i=1; i<=N; i++)
			Ans = min(Ans, getOp(A.x, St[i].x, abs(A.y - St[i].y)).first + getT(St[i], B, v_w));

		
		double x0, x1, y0, y1, H;
		//adjacent
		y0 = A.y; x0 = B.x;
		for(int cnt=0; cnt<ITER; cnt++)
		{
			y0 = getOp(A.x, x0, A.y).second;
			x0 = getOp(B.y, y0, B.x).second;
		}
		Ans = min(Ans, getOp(A.x, x0, A.y).first + getT(PT(x0, 0), B, v_w));

		//opposite
		H = abs(A.y - B.y);
		y0 = 0, y1 = 0;
		for(int cnt=0; cnt<ITER; cnt++)
		{
			y0 = getOp(A.x, E.x, H - y1).second + y1;
			y1 = y0 - getOp(E.x-B.x, E.x, y0).second;
		}
		Ans = min(Ans, getOp(A.x, E.x, H - y1).first + getT(PT(0,0), PT(E.x-B.x, y1), v_w));

		//same
		H = abs(A.y - B.y);
		y0 = 0, y1 = 0;
		for(int cnt=0; cnt<ITER; cnt++)
		{
			y0 = (H-y1) - getOp(A.x, 0, H - y1).second;
			y1 = (H-y0) - getOp(B.x, 0, H - y0).second;
		}
		Ans = min(Ans, getOp(A.x, 0, H - y1).first + getT(PT(0,0), PT(B.x, y1), v_w));
		
		//rotate;
		if(t == 8) break;
		if(t % 2 == 0)
		{
			A = A.rotate(E); B = B.rotate(E);
			for(int i=1; i<=N; i++) St[i] = St[i].rotate(E);
			swap(E.x, E.y);
		}
		else swap(A, B);
	}
	printf("%.15lf\n", Ans);

	return 0;
}