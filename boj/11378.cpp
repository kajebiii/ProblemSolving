// =====================================================================================
//
//       Filename:  11378.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 18:05:56
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
const int MAX_V = 2e3 + 200;

struct LINE{int to, cap, rev;};
int N, M, K;
vector<LINE> V[MAX_V];
void addLine(int from, int to, int cap)
{
	V[from].pb((LINE){to, cap, (int)V[to].size()});
	V[to].pb((LINE){from, 0, (int)V[from].size()-1});
}

int level[MAX_V], iter[MAX_V];
int dfs(int v, int e, int f)
{
	if(v == e) return f;
	for(int &i = iter[v]; i < V[v].size(); i++)
	{
		LINE &l = V[v][i]; int d;
		if(l.cap > 0 && level[l.to] > level[v] && (d = dfs(l.to, e, min(f, l.cap)) > 0))
		{
			l.cap -= d;
			V[l.to][l.rev].cap += d;
			return d;
		}
	}
	return 0;
}
int networkFlow(int s, int e)
{
	int flow = 0;
	while(true)
	{
		for(int i=s; i<=e; i++) level[i] = -1;
		queue<int> Q; Q.push(s); level[s] = 0;
		while(!Q.empty() && level[e] < 0)
		{
			int v = Q.front(); Q.pop();
			for(LINE &l : V[v]) if(l.cap > 0 && level[l.to] < 0)
				{level[l.to] = level[v] + 1; Q.push(l.to);}
		}
		if(level[e] < 0) return flow;
		for(int i=s; i<=e; i++) iter[i] = 0;
		int f; while((f=dfs(s, e, INF) > 0)) flow += f;
	}
}
int main() {	
	cin >> N >> M >> K;
	int S = 0, E = N+1 + M+1, base = N+1; //0, 1-N, N+1, N+1 + 1-M, N+1+M+1;
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		while(k--)
		{
			int x; scanf("%d", &x);
			addLine(i, base+x, 1);
		}
		addLine(0, i, 1);
		addLine(base, i, K);
	}
	for(int i=1; i<=M; i++) addLine(base+i, E, 1);
	addLine(0, base, K);
	
	printf("%d\n", networkFlow(S, E));
	return 0;
}










