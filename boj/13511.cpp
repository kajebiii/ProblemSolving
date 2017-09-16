// =====================================================================================
//
//       Filename:  13511.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  11/16/2016 21:38:34
//       Revision:  none
//       Compiler:  g++
//
//         Author:  JongBeom Kim (KJBS2), qja0950@gmail.com
//   Organization:  KJBS2
//
// =====================================================================================

#include <stdio.h>
#include <functional>
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
#include <assert.h>

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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};

const int MAX_N = 1e5 + 100, LOG_N = 20;

int N; vector<pi> V[MAX_N];
int P[MAX_N][LOG_N+1], D[MAX_N];
ll W[MAX_N][LOG_N+1];
void dfs(int v, int p)
{
	D[v] = D[p] + 1; P[v][0] = p;
	for(int i=1; i<=LOG_N; i++) 
		P[v][i] = P[P[v][i-1]][i-1], 
		W[v][i] = W[v][i-1] + W[P[v][i-1]][i-1];
	for(pi &temp : V[v]) if(temp.fi != p) 
		W[temp.fi][0] = temp.se, dfs(temp.fi, v);
}
int getLCA(int a, int b)
{
	if(D[a] > D[b]) swap(a, b);
	int d = D[b] - D[a];
	for(int i=0; i<=LOG_N; i++) if((1<<i) & d) b = P[b][i];
	if(a == b) return a;
	for(int i=LOG_N; i>=0; i--) if(P[a][i] != P[b][i])
		a = P[a][i], b = P[b][i];
	return P[a][0];
}
ll getL(int x, int p)
{
	int diff = D[x] - D[p];
	ll result = 0;
	for(int i=0; i<=LOG_N; i++) if(diff & (1<<i))
		result += W[x][i], x = P[x][i];
	return result;
}
int getK(int x, int k)
{
	for(int i=0; i<=LOG_N; i++) if(k & (1<<i)) x = P[x][i];
	return x;
}
int main()
{
	cin >> N;	
	for(int i=1; i<N; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y, c)); V[y].pb(mp(x, c));
	}
	dfs(1, 0);

	int Q; cin >> Q;
	for(int i=0; i<Q; i++)
	{
		int t, x, y, k;
		scanf("%d%d%d", &t, &x, &y);
		int lca = getLCA(x, y);
		if(t == 1) printf("%lld\n", getL(x, lca) + getL(y, lca));
		else
		{
			scanf("%d", &k);
			if(D[x] - D[lca] >= k) printf("%d\n", getK(x, k-1));
			else printf("%d\n", getK(y, D[x] + D[y] - D[lca] - D[lca] - k + 1));
		}
	}
	return 0;
}








