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

typedef long double ld;
typedef pair<ld, ld> pld;
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
pld operator -(pld x, pld y) { return mp(x.fi-y.fi, x.se-y.se); }
pld operator +(pld x, pld y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;

int N[2]; pld P[2][2222][2];
long double dis(pld x, pld y)
{
	long double difx = x.fi - y.fi;
	long double dify = x.se - y.se;
	return sqrt(difx*difx + dify*dify);
}
long double getDis(int k, int i, int o, int j)
{
	ld now = 1.0 * INF * INF;
	pld A = P[k][i][0], B = P[k][i][1], C = P[1-k][o][j];
	now = min(dis(A, C), dis(B, C));
	B = B - A; C = C - A;
	ld t = (C.fi * B.fi + C.se * B.se) / (B.fi * B.fi + B.se * B.se);
	B.fi *= t; B.se *= t;
	if(t >= 0 && t <= 1) now = min(now, dis(A+B, C+A));
	return now;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N[0] >> N[1];
	for(int k=0; k<2; k++) for(int i=0; i<N[k]; i++) for(int j=0; j<2; j++)
		scanf("%Lf%Lf", &P[k][i][j].fi, &P[k][i][j].se);

	ld ans = 1.0 * INF * INF;
	for(int k=0; k<2; k++) for(int i=0; i<N[k]; i++)
		for(int o=0; o<N[1-k]; o++) for(int j=0; j<2; j++)
			ans = min(ans, getDis(k, i, o, j));

	printf("%.15Lf", ans);
	return 0;
}