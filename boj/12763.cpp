// =====================================================================================
//
//       Filename:  12763.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:54:06
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
const int MAX_N = 111, MAX_T = 10101;

int N, T, M, L, Dy[MAX_T][MAX_N];
vector<pair<int, pi> > V[MAX_N];
int main() {
	cin >> N >> T >> M >> L;
	for(int i=0; i<L; i++)
	{
		int x, y, t, m; scanf("%d%d%d%d", &x, &y, &t, &m);
		V[x].pb(mp(y, mp(t, m)));
		V[y].pb(mp(x, mp(t, m)));
	}
	for(int i=0; i<=T; i++) for(int j=1; j<=N; j++) Dy[i][j] = INF;
	Dy[0][1] = 0;
	for(int p=1; p<=T; p++) for(int i=1; i<=N; i++)
		for(auto l : V[i])
		{
			int j = l.fi, t = l.se.fi, m = l.se.se;
			if(t > p) continue;
			if(Dy[p-t][j] == INF) continue;
			Dy[p][i] = min(Dy[p][i], Dy[p-t][j] + m);
		}
	int ans = INF;
	for(int p=0; p<=T; p++) ans = min(ans, Dy[p][N]);
	if(ans == INF || ans > M) ans = -1;
	cout << ans;
	return 0;
}










