// =====================================================================================
//
//       Filename:  1939.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 17:05:30
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
const int MAX_N = 1e4 + 100;

int N, M;
bool Dis[MAX_N];
vector<pi> V[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y, c)); V[y].pb(mp(x, c));
	}
	int S, E; cin >> S >> E;
	int s = 1, e = INF/2;
	while(s < e)
	{
		int m = (s + e + 1) / 2;
		for(int i=1; i<=N; i++) Dis[i] = false;
		queue<int> Q; Q.push(S); Dis[S] = true;
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop();
			for(pi &l : V[now])
				if(Dis[l.fi] == false && l.se >= m)
				{
					Dis[l.fi] = true;
					Q.push(l.fi);
				}
		}
		if(Dis[E] == true) s = m;
		else e = m-1;
	}
	printf("%d\n", s);
	return 0;
}










