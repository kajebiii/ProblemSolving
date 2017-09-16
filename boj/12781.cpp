#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

pi P[4];
int ccw(int x, int y, int z)
{
	pi &a = P[x], &b = P[y], &c = P[z];
	int d = (b.fi - a.fi) * (c.se - a.se) - (c.fi - a.fi) * (b.se - a.se);
	if(d > 0) return 1;
	if(d < 0) return -1;
	return 0;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	for(int i=0; i<4; i++) scanf("%d%d", &P[i].fi, &P[i].se);
	if(ccw(0, 1, 2) * ccw(0, 1, 3) < 0 && ccw(2, 3, 0) * ccw(2, 3, 1) < 0)
		puts("1");
	else
		puts("0");
	return 0;
}