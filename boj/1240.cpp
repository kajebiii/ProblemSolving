// =====================================================================================
//
//       Filename:  1240.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 03:56:17
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1e3 + 100;

int N, M, Pa[15][MAX_N], Dis[MAX_N], Lv[MAX_N];
vector<pi> V[MAX_N];
void dfs(int v, int p)
{
	Pa[0][v] = p;
	for(pi l : V[v]) if(l.fi != p)
	{
		Dis[l.fi] = Dis[v] + l.se;
		Lv[l.fi] = Lv[v] + 1;
		dfs(l.fi, v);
	}
}
int lca(int x, int y)
{
	if(Lv[x] > Lv[y]) swap(x, y);
	for(int p=11; p>=0; p--) 
		if((Lv[y] - Lv[x] & (1<<p)))
			y = Pa[p][y];
	if(x == y) return x;
	for(int p=11; p>=0; p--)
		if(Pa[p][x] != Pa[p][y])
			x = Pa[p][x], y = Pa[p][y];
	return Pa[0][x];
}
int main() {	
	cin >> N >> M;
	for(int i=0; i<N-1; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y, c)); V[y].pb(mp(x, c));
	}
	dfs(1, 0);
	for(int p=1; p<12; p++) for(int i=1; i<=N; i++)
		Pa[p][i] = Pa[p-1][Pa[p-1][i]];
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		int a = lca(x, y);
		printf("%d\n", Dis[x] + Dis[y] - 2 * Dis[a]);
	}
	return 0;
}










