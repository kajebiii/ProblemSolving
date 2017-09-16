#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_N = 2e3 + 100;

typedef long long ll;

struct PT
{
	int x, y;
	PT() : x(0), y(0) {}
	PT(int x_, int y_) : x(x_), y(y_) {}
	PT operator-(PT &o) { return PT(x-o.x, y-o.y); }
	PT operator+(PT &o) { return PT(x+o.x, y+o.y); }
};
struct DPT
{
	double x, y;
	DPT() : x(0), y(0) {}
	DPT(PT &o) : x(o.x), y(o.y) {}
	DPT(double x_, double y_) : x(x_), y(y_) {}
	DPT operator-(DPT &o) { return DPT(x-o.x, y-o.y); }
	DPT operator+(const DPT &o) const{ return DPT(x+o.x, y+o.y); }
	DPT operator*(double k) { return DPT(x*k, y*k); }
	DPT operator/(double k) { return DPT(x/k, y/k); }
	double dot(DPT &o){return x*o.x + y*o.y;}
	double dist() {return sqrt(x*x+y*y); }
	DPT norm() {return DPT(x, y) / dist(); }
};
int gccw(PT &a, PT &b, PT &c)
{
	int dx[2] = {b.x-a.x, c.x-a.x};
	int dy[2] = {b.y-a.y, c.y-a.y};
	ll val = 1ll * dx[0] * dy[1] - 1ll * dx[1] * dy[0];
	if(val == 0) return 0;
	return val / abs(val);
}

int N, findC; PT P[MAX_N];

void find_triangle(int a, int k)
{
	DPT candi[3], now[3];
	for(int i=0; i<3; i++) now[i] = DPT(P[(a+i) % N]);
	for(int i=0; i<3; i++)
	{
		DPT a = now[(i+1) % 3] - now[i];
		DPT b = now[(i+2) % 3] - now[i];
		double ang = acos(a.dot(b) / a.dist() / b.dist());
		double how = 4000 / sin(ang / 2);
		DPT mid = a.norm() + b.norm(); mid = mid.norm();
		candi[i] = mid * how;
		candi[i] = candi[i] + now[i];
		if(k == 1) break;
	}
	if(k == 1)
	{
		printf("%lf %lf\n", candi[0].x, candi[0].y);
		return;
	}
	bool flag = false;
	for(int i=0; i<3; i++)
	{
		DPT diff = candi[(i+1)%3] - candi[i];
		if(diff.dist() >= 8000)
		{
			for(int j=0; j<2; j++) printf("%lf %lf\n", candi[(i+j)%3].x, candi[(i+j)%3].y);
			flag = true;
			break;
		}
	}
	if(!flag) puts("impossible");
}

bool Memo[MAX_N];
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d%d", &P[i].x, &P[i].y);
	if(N == 3)
	{
		find_triangle(0, 2);
		return 0;
	}
	for(int a=0; a<N; a++)
	{
		int b = (a+1) % N, c = (b+1) % N;
		int ch[3] = {a, b, c};
		bool isGood = true;
		if(gccw(P[a], P[b], P[c]) >= 0) continue;
		for(int j=3; j<N; j++)
		{
			int o = (a+j) % N;
			bool isIn = true;
			for(int k=0; k<3; k++)
			{
				if(gccw(P[ch[k]], P[ch[(k+1)%3]], P[o]) > 0)
				{
					isIn = false;
					break;
				}
			}
			if(isIn) { isGood = false; break; }
		}
		Memo[a] = isGood;
	}
	for(int i=0; i<N; i++) for(int b=2; b<=N-2; b++)
	{
		int j = (i+b) % N;
		if(Memo[i] & Memo[j])
		{
//			printf("%d %d\n", i, j);
			find_triangle(i, 1);
			find_triangle(j, 1);
			return 0;
		}
	}
	return 0;
}