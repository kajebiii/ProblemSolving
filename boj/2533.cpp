// =====================================================================================
//
//       Filename:  2533.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 01:05:20
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
const int MAX_N = 1e6 + 1000;

int N, Dy[MAX_N][2];
vector<int> V[MAX_N];
void findDy(int v, int p)
{
	Dy[v][0] = 0;
	Dy[v][1] = 1;
	for(int w : V[v])
	{
		if(w == p) continue;
		findDy(w, v);
		Dy[v][0] += min(Dy[w][1], Dy[w][1]);
		Dy[v][1] += min(Dy[w][0], Dy[w][1]);
	}
}
int main() {
	cin >> N; for(int i=1, x, y; i<N; i++)
	{
		scanf("%d%d", &x, &y);
		V[x].pb(y); V[y].pb(x);
	}
	findDy(1, -1);
	printf("%d", min(Dy[1][0], Dy[1][1]));
	return 0;
}










