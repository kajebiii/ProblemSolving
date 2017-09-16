// =====================================================================================
//
//       Filename:  9694.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 23:12:50
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, M, Dis[22], P[22];
vector<pi> V[22];
void printAns(int v)
{
	if(v == -1) return;
	printAns(P[v]);
	printf("%d ", v);
}
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
	{
		scanf("%d%d", &M, &N);
		for(int i=0; i<M; i++)
		{
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			V[x].pb(mp(y, c));
			V[y].pb(mp(x, c));
		}
		for(int i=0; i<N; i++) Dis[i] = INF, P[i] = -1;
		priority_queue<pi> Q;
		Q.push(mp(-0, 0));
		Dis[0] = 0;
		while(!Q.empty())
		{
			int cost = -Q.top().fi, now = Q.top().se; Q.pop();
			if(Dis[now] < cost) continue;
			for(pi x : V[now])
				if(Dis[x.fi] > cost + x.se)
				{
					Q.push(mp(-(Dis[x.fi] = cost + x.se), x.fi));
					P[x.fi] = now;
				}
		}
		printf("Case #%d: ", t);
		if(Dis[N-1] == INF) printf("-1");
		else printAns(N-1);
		puts("");
		for(int i=0; i<N; i++)
		{
			V[i].clear();
			V[i].shrink_to_fit();
		}
	}
	return 0;
}










