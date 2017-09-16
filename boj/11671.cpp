#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const double RADIUS = 6370, EPS = 1e-9, PI = atan(1) * 4;

struct PT
{
	double co[3];
	PT(double ph, double th)
	{
		ph *= PI / 180; th *= PI / 180;
		co[0] = cos(ph) * cos(th);
		co[1] = cos(ph) * sin(th);
		co[2] = sin(ph);
	}
	PT(double x, double y, double z) { co[0] = x; co[1] = y; co[2] = z; }
	PT() { co[0] = co[1] = co[2] = 0; }
	PT operator+(const PT &o) const
	{
		PT res; for(int i=0; i<3; i++) res.co[i] = co[i] + o.co[i];
		return res;
	}
	PT operator-(const PT &o) const
	{
		PT res; for(int i=0; i<3; i++) res.co[i] = co[i] - o.co[i];
		return res;
	}
	PT operator*(const double &d) const
	{
		PT res; for(int i=0; i<3; i++) res.co[i] = co[i] * d;
		return res;
	}
	PT operator/(const double &d) const
	{
		PT res; for(int i=0; i<3; i++) res.co[i] = co[i] / d;
		return res;
	}
	PT cross(const PT &o) const
	{
		PT res;
		for(int i=0; i<3; i++)
		{
			int a = (i+1) % 3, b = (i+2) % 3;
			res.co[i] = co[a] * o.co[b] - co[b] * o.co[a];
		}
		return res;
	}
	double dot(const PT &o) const
	{
		double res = 0 ;
		for(int i=0; i<3; i++) res += co[i] * o.co[i];
		return res;
	}
	double dis() const
	{
		double res = 0;
		for(int i=0; i<3; i++) res += co[i] * co[i];
		return sqrt(res);
	}
};


double arc(PT &a, PT &b)
{
	return asin((a - b).dis() / 2) * 2;
}

const int MAX_C = 40;

int C, F;
vector<PT> Con[MAX_C];
vector<PT> Fli;
int main()
{
	scanf("%d", &C);
	for(int l=0; l<C; l++)
	{
		int k; scanf("%d", &k);
		for(int i=0; i<k; i++)
		{
			double x, y; scanf("%lf%lf", &x, &y);
			Con[l].push_back(PT(x, y));
		}
	}
	scanf("%d", &F);
	for(int i=0; i<F; i++)
	{
		double x, y; scanf("%lf%lf", &x, &y);
		Fli.push_back(PT(x, y));
	}

	double dis = 0;
	for(int i=1; i<F; i++)
		dis += arc(Fli[i-1], Fli[i]);

	double dist[2] = {0, 0}; int type = 0;
	for(int f=1; f<F; f++)
	{
		PT &pa = Fli[f-1], &pb = Fli[f];
		PT nf = pa.cross(pb);

		vector<PT> list;
		for(int c=0; c<C; c++)
		{
			int k = Con[c].size();
			for(int i=0; i<k; i++)
			{
				PT &pc = Con[c][i], &pd = Con[c][(i+1)%k];
				PT nc = pc.cross(pd);

				PT d = nf.cross(nc);
				double dis = d.dis();
				if(abs(dis) < EPS) continue;

				d = d / dis;
				// there are two points (candidate)
				for(int _=0; _<2; _++, d = d * -1)
				{
					
					if(abs(arc(pa, pb) - arc(pa, d) - arc(pb, d)) < EPS)
						if(abs(arc(pc, pd) - arc(pc, d) - arc(pd, d)) < EPS)
						{
							list.push_back(d);
						}
				}
			}
		}

		sort(list.begin(), list.end(), [&](PT &a, PT &b)
		{
			return arc(a, pa) < arc(b, pa);
		});
		PT past = pa;
		
		for(PT &p : list)
		{
			dist[type] += arc(past, p);
			type = 1 - type;
			past = p;
		}
		
		dist[type] += arc(past, pb);
	}
	printf("%.15lf %.15lf", dis * RADIUS, dist[1] / dis * 100);
	return 0;
}