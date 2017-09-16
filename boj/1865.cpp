// =====================================================================================
//
//       Filename:  1865.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 18:08:01
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

int N, M, W, Dis[555];
vector<pi> V[555];
bool Visit[555];
void dfs(int n)
{
	if(Visit[n] == true) return;
	Visit[n] = true;
	for(pi &l : V[n]) dfs(l.fi);
}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d%d", &N, &M, &W);
		for(int i=1; i<=M; i++)
		{
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			V[x].pb(mp(y, c)); V[y].pb(mp(x, c));
		}
		for(int i=1; i<=W; i++)
		{
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			V[x].pb(mp(y, -c));
		}

		for(int i=1; i<=N; i++) Dis[i] = INF;
		for(int i=1; i<=N; i++) Visit[i] = false;
		for(int i=1; i<=N; i++)
		{
			if(Visit[i] == true) continue;
			Dis[i] = 0;
			dfs(i);
		}
		bool flag = false;
		for(int k=0; k<N; k++)
		{
			flag = false;
			for(int i=1; i<=N; i++) if(Dis[i] != INF)
				for(pi &l : V[i]) if(Dis[l.fi] > Dis[i] + l.se)
				{
					flag = true;
					Dis[l.fi] = Dis[i] + l.se;
				}
		}
		if(flag) puts("YES");
		else puts("NO");
		for(int i=1; i<=N; i++) V[i].clear(), V[i].shrink_to_fit();
	}
	return 0;
}










