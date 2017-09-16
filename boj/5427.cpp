// =====================================================================================
//
//       Filename:  5427.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 16:20:48
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

int N, M, Dis[1111][1111], Fast[1111][1111];
char Map[1111][1111];
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d", &M, &N);
		for(int i=0; i<N; i++) scanf("%s", Map[i]);
		int sx = -1, sy = -1;
		
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) Dis[i][j] = INF;
		queue<pi> F;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) 
			if(Map[i][j] == '@') 
			{
				Map[i][j] = '.';
				sx = i; sy = j;
			}
			else if(Map[i][j] == '*')
			{
				F.push(mp(i, j));
				Dis[i][j] = 0;
			}
		while(!F.empty())
		{
			pi now = F.front(); F.pop();
			for(int k=0; k<4; k++)
			{
				pi nx = now + Ch[k];
				if(nx.fi < 0 || nx.se < 0 || nx.fi >= N || nx.se >= M) continue;
				if(Dis[nx.fi][nx.se] == INF && Map[nx.fi][nx.se] == '.')
				{
					Dis[nx.fi][nx.se] = Dis[now.fi][now.se] + 1;
					F.push(nx);
				}
			}
		}

		for(int i=0; i<N; i++) for(int j=0; j<M; j++) Fast[i][j] = INF; Fast[sx][sy] = 0;
		F.push(mp(sx, sy));
		int ans = INF;
		while(!F.empty())
		{
			pi now = F.front(); F.pop();
			if(now.fi == 0 || now.se == 0 || now.fi == N-1 || now.se == M-1)
				ans = min(ans, Fast[now.fi][now.se]);
			for(int k=0; k<4; k++)
			{
				pi nx = now + Ch[k];
				if(nx.fi < 0 || nx.se < 0 || nx.fi >= N || nx.se >= M) continue;
				if(Fast[nx.fi][nx.se] == INF && Map[nx.fi][nx.se] == '.' && Dis[nx.fi][nx.se] > Fast[now.fi][now.se] + 1)
				{
					Fast[nx.fi][nx.se] = Fast[now.fi][now.se] + 1;
					F.push(nx);
				}
			}
		}

		if(ans == INF) puts("IMPOSSIBLE");
		else printf("%d\n", ans+1);
	}
	return 0;
}










