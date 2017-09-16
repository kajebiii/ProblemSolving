// =====================================================================================
//
//       Filename:  2157.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 15:14:47
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

int N, M, K, Dy[333][333];
vector<pi> V[333];
int main() {
	cin >> N >> M >> K;
	for(int p=1; p<=N; p++) for(int i=1; i<=N; i++) Dy[p][i] = -INF;
	for(int i=1; i<=K; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		if(x > y) continue;
		V[y].pb(mp(x, c));
	}

	Dy[1][1] = 0;
	for(int p=2; p<=M; p++) for(int i=1; i<=N; i++) for(pi l : V[i])
		Dy[p][i] = max(Dy[p][i], Dy[p-1][l.fi] + l.se);
	int ans = 0;
	for(int p=1; p<=M; p++)
		ans = max(ans, Dy[p][N]);
	cout << ans;
	return 0;
}










