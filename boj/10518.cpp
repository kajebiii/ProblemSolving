#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int sign(int x) {return (x>0) - (x<0);}

struct PT
{
	int x, y;
	int type;
	PT() : x(0), y(0) {}
	PT(int x_, int y_, int t_) : x(x_), y(y_), type(t_) {}

	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y, 0); }
	PT operator+(const PT &o) const { return PT(x+o.x, y+o.y, 0); }
	bool operator==(const PT &o) const { return x==o.x && y==o.y && type==o.type;}
	int dot(const PT &o) const {return x*o.x + y*o.y;}
	int cross(const PT &o) const {return x*o.y - y*o.x;}
	double size() const {return sqrt(x*x+y*y); }
};
int gccw(const PT &a, const PT &b, const PT &c){return sign((b-a).cross(c-a));}
bool isIn(const PT &p, const PT &a, const PT &b, const PT &c)
{
	int val[3] = {gccw(a, b, p), gccw(b, c, p), gccw(c, a, p)};
	bool same = true; for(int i=0; i<3; i++) same &= (val[i] == val[(i+1)%3]);
	return same;
}

int iN, oN;
vector<PT> inner, outer;
int main()
{
	scanf("%d", &iN); for(int i=0, x, y; i<iN; i++) scanf("%d%d", &x, &y), inner.push_back(PT(x, y, -1));
	scanf("%d", &oN); for(int i=0, x, y; i<oN; i++) scanf("%d%d", &x, &y), outer.push_back(PT(x, y, +1));

	while(true)
	{
		bool change = false;
		for(int i=0; i<inner.size(); i++)
		{
			int j=(i+1)%inner.size(), k=(j+1)%inner.size();
			PT a = inner[i], b = inner[j], c = inner[k];
			if(b.type == -1 && gccw(a, b, c) < 0)
			{
				vector<PT> candi, cv;
				candi.push_back(a); candi.push_back(c);
				for(PT &p : inner) if(isIn(p, a, b, c)) candi.push_back(p);
				for(PT &p : outer) if(isIn(p, a, b, c)) candi.push_back(p);
				sort(candi.begin()+1, candi.end(), [&](const PT &n, const PT &m)
				{
					int ccw = gccw(a, n, m);
					if(ccw < 0) return true;
					if(ccw > 0) return false;
					return (n-a).size() < (m-a).size();
				});
				for(PT &p : candi)
				{
					while(cv.size() > 1 && gccw(cv[cv.size()-2], cv[cv.size()-1], p) >= 0)
						cv.pop_back();
					cv.push_back(p);
				}
				bool sorry = false;
				for(int i=1; i+1<cv.size(); i++)
					if(find(inner.begin(), inner.end(), cv[i]) != inner.end() )
						sorry = true;
				if(sorry) continue;
				inner.erase(inner.begin() + j);
				inner.insert(inner.begin() + j, cv.begin()+1, cv.end()-1);
				change = true;
			}
		}
		if(change == false) break;
	}

	double ans = 0;
	for(int i=0; i<inner.size(); i++)
	{
		int j = (i+1) % inner.size();
		ans += (inner[j]-inner[i]).size();
	}
	printf("%.15lf\n", ans);
	return 0;
}