// =====================================================================================
//
//       Filename:  1446.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 12:04:57
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
const int MAX_D = 1e4 + 100;

int N, D, Dy[MAX_D];
vector<pi> V[MAX_D];
int main() {
	cin >> N >> D;
	for(int i=0; i<D; i++)
		V[i+1].pb(mp(i, 1));
	for(int i=0; i<N; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[y].pb(mp(x, c));
	}
	for(int i=1; i<=D; i++) Dy[i] = INF;
	for(int i=0; i<=D; i++)
		for(pi x : V[i])
			Dy[i] = min(Dy[i], Dy[x.fi] + x.se);
	cout << Dy[D];
	return 0;
}










