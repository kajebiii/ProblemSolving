#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX_P = 1e3 + 50;

struct PT
{
	int x, y;
	PT(int x_, int y_) : x(x_), y(y_) {}
};

int ccw(PT &a, PT &b, PT &c)
{
	int dx[2] = {b.x - a.x, c.x - a.x};
	int dy[2] = {b.y - a.y, c.y - a.y};
	int val = dx[0] * dy[1] - dx[1] * dy[0];
	if(val == 0) return val;
	return val / abs(val);
}
bool isCross(PT &a, PT &b, PT &c, PT &d)
{
	int val[4] = {ccw(a, b, c), ccw(a, b, d), ccw(c, d, a), ccw(c, d, b)};
	return val[0] * val[1] <= 0 && val[2] * val[3] <= 0;
}

int W, P;
vector<PT> We, En;
int Ix[MAX_P];
vector<int> Ed[MAX_P];
int Color[MAX_P];

bool coloring(int v, int c)
{
	if(Color[v] == 0) Color[v] = c;
	else return Color[v] == c;
	for(int w : Ed[v])
		if(!coloring(w, 3-c))
			return false;
	return true;
}

int main()
{
	scanf("%d%d", &W, &P);
	for(int i=0, x, y; i<W; i++) scanf("%d%d", &x, &y), We.push_back(PT(x, y));
	for(int i=0; i<P; i++)
	{
		int ix; scanf("%d", &ix); Ix[i] = ix - 1;
		int x, y; scanf("%d%d", &x, &y);
		En.push_back(PT(x, y));
	}
	for(int i=0; i<P; i++) for(int j=i+1; j<P; j++)
		if(Ix[i] != Ix[j] && isCross(We[Ix[i]], En[i], We[Ix[j]], En[j]))
			Ed[i].push_back(j), Ed[j].push_back(i);

	bool isGood = true;
	for(int i=0; i<P; i++)
		if(Color[i] == 0) if(coloring(i, 1) == false)
		{
			isGood = false;
			break;
		}

	if(isGood)
		puts("possible");
	else
		puts("impossible");
	return 0;
}