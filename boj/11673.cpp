#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct PT
{
	double co[2];
	PT(double x, double y)
	{
		co[0] = x;
		co[1] = y;
	}
	PT()
	{
		co[0] = 0;
		co[1] = 0;
	}
	PT operator-(const PT &o) const
	{
		PT res; for(int k=0; k<2; k++) res.co[k] = co[k] - o.co[k];
		return res;
	}
	PT operator+(const PT &o) const
	{
		PT res; for(int k=0; k<2; k++) res.co[k] = co[k] + o.co[k];
		return res;
	}
	PT operator*(const double d) const
	{
		PT res; for(int k=0; k<2; k++) res.co[k] = co[k] * d;
		return res;
	}
};
struct SEG
{
	PT P[2];
	bool same[2];
};

const int MAX_N = 10;
const double EPS = 1e-9;

PT ref(PT p, SEG l)
{
	PT res = p;
	for(int k=0; k<2; k++) if(l.same[k] == true)
		res.co[k] = l.P[0].co[k] * 2 - res.co[k];
	return res;
}
double cross(PT a, PT b)
{
	return a.co[0] * b.co[1] - a.co[1] * b.co[0];
}
double how(SEG a, SEG b)
{
	double all = cross(a.P[1] - a.P[0], b.P[1] - b.P[0]);
	double as = cross(b.P[0] - a.P[0], b.P[1] - b.P[0]) / all;
	double bs = cross(b.P[0] - a.P[0], a.P[1] - a.P[0]) / all;
	if(-EPS < as && as < 1 + EPS && -EPS < bs && bs < 1 + EPS)
		return as;
	return -1;
}

int N; PT Des;
SEG Seg[MAX_N];

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for(int k=0; k<2; k++) scanf("%lf", &Des.co[k]);
	for(int i=0; i<N; i++) 
	{
		for(int j=0; j<2; j++) for(int k=0; k<2; k++) scanf("%lf", &Seg[i].P[j].co[k]);
		for(int k=0; k<2; k++) Seg[i].same[k] = (Seg[i].P[0].co[k] == Seg[i].P[1].co[k]);
	}
	
	int ans = -1;
	for(int t=N; t>=0; t--)
	{
		int Ch[MAX_N];
		for(int i=0; i<N; i++) Ch[i] = -1;
		for(int i=N-t; i<N; i++) Ch[i] = i - (N-t);

		SEG tSeg[MAX_N]; int ord[MAX_N], Chk[MAX_N];
		do
		{
			bool isPos = true;
			for(int i=0; i<N; i++) tSeg[i] = Seg[i];
			for(int i=0; i<N; i++) Chk[i] = -1;
			for(int i=0; i<N; i++) if(Ch[i] != -1) ord[Ch[i]] = i;
			
			PT tDes = Des;
			for(int l=t-1; l>=0; l--)
				tDes = ref(tDes, tSeg[ord[l]]);
			SEG toDes; toDes.P[0] = PT(0, 0), toDes.P[1] = tDes;
			for(int l=0; l<t; l++)
			{
				int now = ord[l];
				Chk[now] = 0;
				//check intersect
				bool isInter = false;
				double nowh = how(toDes, tSeg[now]);
				if(nowh < 0) { isPos = false; break; }
				for(int i=0; i<N; i++) if(Chk[i] == -1)
				{
					double nexth = how(toDes, tSeg[i]);
					if(nexth < 0) continue;
					if(nexth < nowh) {isInter = true; break;}
				}
				if(isInter == true) {isPos = false; break;}

				// ref
				for(int i=0; i<N; i++) if(Chk[i] == -1)
					for(int k=0; k<2; k++) 
						tSeg[i].P[k] = ref(tSeg[i].P[k], tSeg[now]);
				toDes.P[0] = toDes.P[0] + (toDes.P[1] - toDes.P[0]) * nowh;
			}
			//last check
			for(int i=0; i<N; i++) if(Chk[i] == -1)
			{
				int nexth = how(toDes, tSeg[i]);
				if(nexth < 0) continue;
				if(nexth < 1) {isPos = false; break;}
			}
			
			if(isPos == false) continue;

			ans = t;
			break;
		}
		while(next_permutation(Ch, Ch+N));

		if(ans != -1) break;
	}

	if(ans == -1) puts("impossible");
	else printf("%d\n", ans);
	return 0;
}
