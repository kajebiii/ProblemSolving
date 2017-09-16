// =====================================================================================
//
//       Filename:  11437.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 15:45:40
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
#include <assert.h>

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

int N, M, P[21][55555], Lv[55555];
vector<int> V[55555];
void dfs(int v, int p, int lv)
{
	P[0][v] = p;
	Lv[v] = lv;
	for(int w : V[v])
		if(w != p) dfs(w, v, lv+1);
}
int main() {
	cin >> N; 
	for(int i=1, x, y; i<N; i++)
	{
		scanf("%d%d", &x, &y);
		V[x].pb(y); V[y].pb(x);
	}
	dfs(1, 0, 0);
	for(int p=1; p<=20; p++) for(int i=1; i<=N; i++)
		P[p][i] = P[p-1][P[p-1][i]];
	cin >> M;
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		if(Lv[x] > Lv[y]) swap(x, y);
		for(int p=20; p>=0; p--) if((Lv[y]-Lv[x]) & (1<<p)) y = P[p][y];
		if(x == y) {printf("%d\n", x); continue;}
		for(int p=20; p>=0; p--) if(P[p][x] != P[p][y]) x = P[p][x], y = P[p][y];
		x = P[0][x]; printf("%d\n", x);
	}
	return 0;
}










