// =====================================================================================
//
//       Filename:  13512.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  11/17/2016 20:33:00
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

const int MAX_N = 1e5 + 100, LOG_N = 20;

struct IT
{
	int *T, P;
	IT(int N)
	{
		for(P=1; P<N; P<<=1);
		T = new int[2*P];
		for(int i=1; i<2*P; i++) T[i] = INF;
	}
	void update(int v, int l)
	{
		T[v = P + v] = l;
		while(v/=2) T[v] = min(T[v*2], T[v*2+1]);
	}
	int query(int a, int b)
	{
		a += P, b += P;
		int result = INF;
		while(a <= b)
		{
			if(a%2 == 1) result = min(result, T[a++]);
			if(b%2 == 0) result = min(result, T[b--]);
			a /= 2; b /= 2;
		}
		return result;
	}
};
int N; vector<int> V[MAX_N];
int S[MAX_N], D[MAX_N], P[MAX_N][LOG_N+1];
void initDFS(int v, int p)
{
	S[v] = 1; D[v] = D[p] + 1; P[v][0] = p;
	for(int i=1; i<=LOG_N; i++) P[v][i] = P[P[v][i-1]][i-1];
	for(int w : V[v]) if(w != p) initDFS(w, v), S[v] += S[w];
	return;
}

vector<int> PI; vector<vector<int> > Ps;
vector<IT> ITs;
void doHLD(int root)
{	
	Ps.clear(); PI.resize(N+1, -1);
	queue<int> Q; Q.push(root);
	while(!Q.empty())
	{
		int v = Q.front(); Q.pop();
		int p = P[v][0];
		for(int w : V[v]) if(w != p) Q.push(w);
		if(v == root) continue;
		if(S[v] * 2 >= S[p] && p != root)
			Ps[PI[p]].pb(v), PI[v] = PI[p];
		else
			PI[v] = Ps.size(), Ps.pb(vector<int>({p, v}));
	}
	ITs.clear(); ITs.reserve(Ps.size());
	for(auto &path : Ps)
	{
		ITs.pb(IT(path.size() - 1));
		for(int i=1; i<path.size(); i++) ITs.back().update(i-1, INF);
	}
}
int find(int ix, int v)
{
	int root = Ps[ix][0];
	return D[v] - D[root] - 1;
}

int Ans[MAX_N];
int getQuery(int p, int v)
{
	if(p == v) return INF;
	int ix = PI[v], r = find(ix, v);
	int top = Ps[ix][0];
	int left = ITs[ix].query(0, r);
	int result = INF;
	if(left != INF) Ans[result = D[top] + left + 1] = Ps[ix][left+1];
	return min(getQuery(p, top), result);
}

int Color[MAX_N];
int main()
{	
	cin >> N; 
	for(int x, y, i=1; i<N; i++)
		scanf("%d%d", &x, &y), V[x].pb(y), V[y].pb(x);
	initDFS(1, 0);
	doHLD(1);
	int Q; cin >> Q;
	for(int k, x, i=0; i<Q; i++)
	{
		scanf("%d%d", &k, &x);
		if(k == 1)
		{
			Color[x] = 1 - Color[x];
			if(x == 1) continue;
			int where = find(PI[x], x);
			ITs[PI[x]].update(where, Color[x]==1?where:INF);
		}
		else
		{
			int get = getQuery(1, x);
			printf("%d\n", Color[1]==1?1:get==INF?-1:Ans[get]);
		}
	}
	return 0;
}










