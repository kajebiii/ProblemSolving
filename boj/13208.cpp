// =====================================================================================
//
//       Filename:  13208.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 09:19:58
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
const int MAX_N = 505;

int N, M, C[MAX_N];
vector<int> V[MAX_N];
vector< pair<int, pi> > S;

int UNF[MAX_N*MAX_N];
vector<int> G[MAX_N*MAX_N];
bool Chk[MAX_N][MAX_N];
int AnsMin[MAX_N][MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
void U(int a, int b, int cost) 
{
	a = F(a); b = F(b); if(a == b) return;
	if(G[a].size() > G[b].size()) swap(a, b);
	for(int x : G[a]) 
	{
		if(F((x%N)*N + x/N) == F(b)) 
		{
			AnsMin[x/N][x%N] = min(AnsMin[x/N][x%N], cost);
			AnsMin[x%N][x/N] = min(AnsMin[x%N][x/N], cost);
		}
		G[b].pb(x);
	}
	UNF[F(a)] = F(b);
	G[a].clear(); G[a].shrink_to_fit();
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &C[i]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) 
		S.pb(mp(C[i]*C[j], mp(i, j)));
	for(int i=0; i<M; i++)
	{
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		V[x].pb(y); V[y].pb(x);
	}
	sort(S.begin(), S.end());

	for(int i=0; i<N; i++) for(int j=0; j<N; j++) UNF[i*N+j] = i*N+j;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) AnsMin[i][j] = INF;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) G[i*N+j].pb(i*N+j);
	for(auto temp : S)
	{
		int cost = temp.fi;
		int x = temp.se.fi, y = temp.se.se;
		Chk[x][y] = true;
		for(int xx : V[x]) if(Chk[xx][y]) U(xx*N+y, x*N+y, cost);
		for(int yy : V[y]) if(Chk[x][yy]) U(x*N+yy, x*N+y, cost);
	}

	int Q; cin >> Q;
	while(Q--)
	{
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		printf("%d\n", AnsMin[x][y]);
	}

	return 0;
}










