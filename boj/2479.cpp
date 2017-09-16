// =====================================================================================
//
//       Filename:  2479.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 16:22:26
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

int N, K, Nr[MAX_N], Pre[MAX_N], Dis[MAX_N];
map<int, int> Idx;
void printAns(int v)
{
	if(v == 0) return;
	printAns(Pre[v]);
	printf("%d ", v);
}
int main() {
	cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		int now = 0;
		for(int j=1, x; j<=K; j++)
			scanf("%1d", &x), now *= 2, now += x;
		Idx[now] = i;
		Nr[i] = now;
	}
	int S, E; cin >> S >> E;
	for(int i=1; i<=N; i++) Dis[i] = INF;
	queue<int> Q; Q.push(S); Dis[S] = 0;
	while(!Q.empty())
	{
		int ix = Q.front();
		int now = Nr[Q.front()]; Q.pop();
		for(int i=0; i<K; i++)
		{
			int next = now ^ (1<<i);
			if(Idx.count(next) == 0) continue;
			int idx = Idx[next];
			if(Dis[idx] != INF) continue;
			Pre[idx] = ix;
			Dis[idx] = Dis[ix] + 1;
			Q.push(idx);
		}
	}
	if(Dis[E] == INF) puts("-1");
	else printAns(E);
	return 0;
}










