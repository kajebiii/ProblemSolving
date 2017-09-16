// =====================================================================================
//
//       Filename:  11408.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 21:13:50
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

int Match[MAX_V], Visit[MAX_V];
bool findMatch(int v)
{
	if(Visit[v] == 1) return false;
	Visit[v] = 1;
	for(LINE &l : V[v])
		if(Match[l.to-N] == 0 || findMatch(Match[l.to-N]))
		{
			Match[l.to-N] = v;
			return true;
		}
	return false;
}

int Dis[MAX_V], preV[MAX_V], preE[MAX_V];
int mcmf(int s, int e, int f)
{
	int result = 0;
	while(f > 0)
	{
		for(int i=s; i<=e; i++) Dis[i] = INF;
		Dis[s] = 0;
		bool update = true;
		while(update)
		{
			update = false;
			for(int i=s, cnt=0; i<=e; i++, cnt=0) if(Dis[i] != INF)
				for(LINE &l : V[i])
					if(++cnt && l.cap > 0 && Dis[l.to] > Dis[i] + l.cost)
					{
						Dis[l.to] = Dis[i] + l.cost;
						preV[l.to] = i;
						preE[l.to] = cnt-1;
						update = true;
					}
		}
		if(Dis[e] == INF) return -1;

		int amount = f;
		for(int p = e; p != s; p = preV[p]) amount = min(amount, V[preV[p]][preE[p]].cap);
		f -= amount;
		result += amount * Dis[e];
		for(int p = e; p != s; p = preV[p])
		{
			LINE &l = V[preV[p]][preE[p]];
			l.cap -= amount;
			V[l.to][l.rev].cap += amount;
		}
	}
	return result;
}
int main() {
	cin >> N >> M;
	int S = 0, E = N+M+1; // 0 , 1-N, N+(1-M), N+M+1;
	for(int i=1; i<=N; i++)
	{
		int k; scanf("%d", &k);
		while(k--)
		{
			int x, cost; 
			scanf("%d%d", &x, &cost);
			addLine(i, N+x, 1, cost);
		}
	}
	int F = 0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++) Visit[j] = 0;
		if(findMatch(i)) F++;
	}
	for(int i=1; i<=N; i++) addLine(S, i, 1, 0);
	for(int i=1; i<=M; i++) addLine(N+i, E, 1, 0);
	printf("%d\n%d\n", F, mcmf(S, E, F));
	return 0;
}










