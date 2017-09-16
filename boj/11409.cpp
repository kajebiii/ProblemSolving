// =====================================================================================
//
//       Filename:  11409.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 21:46:50
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
const int MAX_V = 888;

struct LINE{int to, cap, cost, rev;};
int N, M;
vector<LINE> V[MAX_V];
void addLine(int from, int to, int cap, int cost)
{
	V[from].pb((LINE){to, cap, cost, (int)V[to].size()});
	V[to].pb((LINE){from, 0, -cost, (int)V[from].size()-1});
}

int Dis[MAX_V], preV[MAX_V], preE[MAX_V];
pi mcmf(int s, int e)
{
	int f = 0, c = 0;
	while(1)
	{
		for(int i=s; i<=e; i++) Dis[i] = INF;
		Dis[s] = 0;
		bool update = true;
		while(update)
		{
			update = false;
			for(int i=s, cnt=0; i<=e; i++, cnt=0) if(Dis[i] != INF)
				for(LINE &l : V[i]) if(++cnt && l.cap > 0 && Dis[l.to] > Dis[i] + l.cost)
				{
					Dis[l.to] = Dis[i] + l.cost;
					preV[l.to] = i;
					preE[l.to] = cnt - 1;
					update = true;
				}
		}
		if(Dis[e] == INF) break;
		int d = INF;
		for(int p=e; p!=s; p=preV[p]) d = min(d, V[preV[p]][preE[p]].cap);
		f += d;
		c += d * Dis[e];
		for(int p=e; p!=s; p=preV[p])
		{
			LINE &l = V[preV[p]][preE[p]];
			l.cap -= d;
			V[l.to][l.rev].cap += d;
		}
	}
	return mp(f, c);
}
int main() {	
	cin >> N >> M;
	int S = 0, E = N+M+1;
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		while(k--)
		{
			int x, cost; scanf("%d%d", &x, &cost);
			addLine(i, N+x, 1, 10000 - cost);
		}
	}
	for(int i=1; i<=N; i++) addLine(S, i, 1, 0);
	for(int i=1; i<=M; i++) addLine(N+i, E, 1, 0);
	pi result = mcmf(S, E);
	printf("%d\n%d", result.fi, 10000 * result.fi - result.se);
	return 0;
}










