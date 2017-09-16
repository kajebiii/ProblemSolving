// =====================================================================================
//
//       Filename:  9466.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 15:51:45
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
const int MAX_N = 1e5 + 100;

int V[MAX_N], N;

int Idx[MAX_N], Low[MAX_N], T, GIx[MAX_N];
vector<vector<int> > G;
stack<int> S;
int SCC(int v)
{
	Idx[v] = Low[v] = ++T; S.push(v);
	if(Idx[V[v]] == 0)
		Low[v] = min(Low[v], SCC(V[v]));
	else if(GIx[V[v]] == 0)
		Low[v] = min(Low[v], Idx[V[v]]);
	if(debug) printf("%d / (%d, %d)\n", v, Idx[v], Low[v]);
	if(Idx[v] == Low[v])
	{
		G.pb(vector<int>());
		while(1)
		{
			int now = S.top(); S.pop();
			G.back().pb(now);
			GIx[now] = G.size();
			if(now == v) break;
		}
	}
	return Low[v];
}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N); 
		for(int i=1; i<=N; i++) scanf("%d", &V[i]);
		for(int i=1; i<=N; i++) Idx[i] = Low[i] = GIx[i] = 0;
		T = 0;
		for(int i=1; i<=N; i++) if(Idx[i] == 0) SCC(i);

		int ans = 0;
		for(auto g : G)
			if(g.size() == 1 && V[g[0]] != g[0])
				ans++;
		printf("%d\n", ans);

		G.clear(); G.shrink_to_fit();
	}
	return 0;
}










