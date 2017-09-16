// =====================================================================================
//
//       Filename:  11377.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 16:55:08
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
const int MAX_N = 1e3 + 100;

struct LINE{int to, cap, rev;};
int N, M, K;
vector<LINE> V[MAX_N*2];
void addLine(int from, int to, int cap)
{
	V[from].pb((LINE){to, cap, (int)V[to].size()});
	V[to].pb((LINE){from, 0, (int)V[from].size()-1});
}

int level[MAX_N*2], iter[MAX_N*2];
int dfs(int v, int e, int f)
{
	if(v == e) return f;
	for(int &i = iter[v]; i < V[v].size(); i++)
	{
		LINE &l = V[v][i]; int d;
		if(l.cap > 0 && level[v] < level[l.to] && (d=dfs(l.to, e, min(f, l.cap)) > 0))
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
		for(int i=0; i<=e; i++) level[i] = -1;
		queue<int> que; level[s] = 0; que.push(s);
		while(!que.empty())
		{
			int v = que.front(); que.pop();
			for(LINE &l : V[v]) if(l.cap>0 && level[l.to] < 0) {level[l.to] = level[v] + 1; que.push(l.to);}
		}
		if(level[e] < 0) return flow;
		for(int i=0; i<=e; i++) iter[i] = 0;
		int f; while(0 < (f = dfs(s, e, INF))) flow += f;
	}
}
int main() {
	
	cin >> N >> M >> K;
	int S = 0, E = N+1 + M + 1, base = N+1;
	//0 start / 1~N / N+1 / N+1 + 1 - N+1 + M / N+1 + M + 1
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		for(int j=0; j<k; j++)
		{
			int x; scanf("%d", &x);
			addLine(i, base+x, 1);
		}
		addLine(0, i, 1);
		addLine(base, i, 1);
	}
	for(int i=1; i<=M; i++) addLine(base+i, E, 1);
	addLine(0, base, K);
	
	printf("%d\n", networkFlow(S, E));
	return 0;
}










