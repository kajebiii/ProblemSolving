// =====================================================================================
//
//       Filename:  11779.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 09:23:10
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
const int MAX_N = 1e3 + 10;

int N, M, Dis[MAX_N], Par[MAX_N];
vector<pi> V[MAX_N];
vector<int> Ans;
void findRoute(int v)
{
	if(v == 0) return;
	findRoute(Par[v]);
	Ans.pb(v);
}
int main() {
	cin >> N >> M;
	for(int i=0, x, y, c; i<M; i++)
		scanf("%d%d%d", &x, &y, &c), V[x].pb(mp(y, c));
	int S, E; cin >> S >> E;
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	for(int i=1; i<=N; i++) Dis[i] = INF;
	Q.push(mp(0, S)); Dis[S] = 0;
	while(!Q.empty())
	{
		pi now = Q.top(); Q.pop();
		if(now.fi > Dis[now.se]) continue;
		if(now.se == E) break;
		for(pi t : V[now.se])
			if(Dis[t.fi] > now.fi + t.se)
			{
				Q.push(mp(Dis[t.fi] = now.fi + t.se, t.fi));
				Par[t.fi] = now.se;
			}
	}
	printf("%d\n", Dis[E]);
	findRoute(E);
	printf("%d\n", (int)Ans.size());
	for(int x : Ans) printf("%d ", x);
	return 0;
}










