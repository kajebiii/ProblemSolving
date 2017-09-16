// =====================================================================================
//
//       Filename:  1504.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:07:27
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 999;

int N, M;
vector<pi> V[MAX_N];
int A[2];
int Dis[2][MAX_N];
int main() {
	cin >> N >> M;
	for(int i=1; i<=M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y,c));
		V[y].pb(mp(x,c));
	}
	scanf("%d%d", &A[0], &A[1]);

	for(int k=0; k<2; k++)
	{
		for(int i=1; i<=N; i++) Dis[k][i] = INF;
		priority_queue<pi> Q; Q.push(mp(-0, A[k]));
		Dis[k][A[k]] = 0;
		while(!Q.empty())
		{
			int c = -Q.top().fi, now = Q.top().se; Q.pop();
			if(Dis[k][now] < c) continue;
			for(pi l : V[now])
				if(Dis[k][l.fi] > c + l.se)
					Q.push(mp(-(Dis[k][l.fi] = c + l.se), l.fi));
		}
	}
	long long ans = 1ll * INF * INF;
	ans = min(ans, 1ll * Dis[0][1] + Dis[0][A[1]] + Dis[1][N]);
	ans = min(ans, 1ll * Dis[1][1] + Dis[1][A[0]] + Dis[0][N]);
	if(ans >= INF)
		puts("-1");
	else
		cout << ans;

	return 0;
}










