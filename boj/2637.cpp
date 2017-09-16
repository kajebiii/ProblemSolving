// =====================================================================================
//
//       Filename:  2637.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:44:34
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
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 111;

int N, M;
int Cnt[MAX_N][MAX_N]; bool Know[MAX_N];
vector<int> Basic;
vector<pi> How[MAX_N];

void dfs(int v)
{
	if(Know[v] == true) return;
	Know[v] = true;
	for(pi &l : How[v])
	{
		dfs(l.fi);
		for(int x : Basic) Cnt[v][x] += Cnt[l.fi][x] * l.se;
	}
}
int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		How[x].pb(mp(y, c));
	}
	for(int i=1; i<=N; i++)
		if(How[i].size() == 0)
		{
			Basic.pb(i);
			Know[i] = true; Cnt[i][i] = 1;
		}
	for(int i=1; i<=N; i++) dfs(i);
	for(int x : Basic) printf("%d %d\n", x, Cnt[N][x]);
	return 0;
}










