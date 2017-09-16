// =====================================================================================
//
//       Filename:  1967.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 17:59:06
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 1e4 + 300;

int N, Dis[MAX_N];
vector<pi> V[MAX_N];

void getDis(int v, int p)
{
	for(pi w : V[v])
	{
		if(w.fi == p) continue;
		Dis[w.fi] = Dis[v] + w.se;
	   getDis(w.fi, v);	
	}
}
int main() {
	cin >> N;
	for(int i=1; i<N; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y,c)); V[y].pb(mp(x,c));
	}
	Dis[1] = 0; getDis(1, -1);
	int F = max_element(Dis+1, Dis+N+1) - Dis;
	Dis[F] = 0; getDis(F, -1);
	int S = max_element(Dis+1, Dis+N+1) - Dis;
	cout << Dis[S];
	return 0;
}










