// =====================================================================================
//
//       Filename:  2206.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/06/2016 20:52:47
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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, M, K, Nr[1111][1111], Dy[11][1111][1111];
int main() {
	cin >> N >> M; K=1;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%1d", &Nr[i][j]);
	for(int k=0; k<=K; k++)
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) Dy[k][i][j] = INF;
	priority_queue<pair<pi, pi> > Q;
	Q.push(mp(mp(-1, 0), mp(0, 0)));
	Dy[0][0][0] = 1;
	while(!Q.empty())
	{
		int dis = -Q.top().fi.fi, p = Q.top().fi.se;
		pi now = Q.top().se; Q.pop();
		for(int k=0; k<4; k++)
		{
			pi n = mp(now.fi + Ch[k].fi, now.se + Ch[k].se);
			if(n.fi < 0 || n.fi >= N || n.se < 0 || n.se >= M) continue;
			int np = p + Nr[n.fi][n.se]; if(np > K) continue;
			if(Dy[np][n.fi][n.se] > dis + 1)
				Q.push(mp(mp(-(Dy[np][n.fi][n.se] = dis+1), np), n));
		}
	}
	int ans = INF;
	for(int i=0; i<=K; i++) ans = min(ans, Dy[i][N-1][M-1]);
	cout << ((ans == INF)?-1:ans);
	return 0;
}










