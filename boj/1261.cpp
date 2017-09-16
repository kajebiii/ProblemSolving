// =====================================================================================
//
//       Filename:  1261.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/03/2016 01:08:37
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

int N, M, Nr[111][111], Dis[111][111];

int main() {
	cin >> M >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%1d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) Dis[i][j] = INF;
	priority_queue<pair<int, pi> > Q;
	Q.push(mp(-0, mp(1, 1)));
	Dis[1][1] = 0;
	while(!Q.empty())
	{
		int cost = -Q.top().fi;
		pi now = Q.top().se; Q.pop();
		if(Dis[now.fi][now.se] < cost) continue;
		for(int k=0; k<4; k++)
		{
			pi n = now + Ch[k];
			if(n.fi < 1 || n.se < 1 || n.fi > N || n.se > M) continue;
			if(Dis[n.fi][n.se] > cost + Nr[n.fi][n.se])
				Q.push(mp(-(Dis[n.fi][n.se] = cost + Nr[n.fi][n.se]), n));
		}
	}
	cout << Dis[N][M];
	return 0;
}










