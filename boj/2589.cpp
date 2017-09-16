// =====================================================================================
//
//       Filename:  2589.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 15:19:14
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

using namespace std;

typedef pair<int, int> pi;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

char Map[55][55];
int Dis[55][55];
int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%s", Map[i]);

	int ans = 0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
	{
		if(Map[i][j] == 'W') continue;
		for(int ii=0; ii<N; ii++) for(int jj=0; jj<M; jj++)
			Dis[ii][jj] = -1;
		queue<pi> Q;
		Dis[i][j] = 0;
		Q.push(mp(i, j));
		
		int last = 0;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			last = Dis[now.fi][now.se];
			for(int k=0; k<4; k++)
			{
				pi next = mp(now.fi + CX[k], now.se + CY[k]);
				if(next.fi < 0 || next.se < 0 || next.fi >= N || next.se >= M) 
					continue;
				if(Map[next.fi][next.se] == 'W') continue;
				if(Dis[next.fi][next.se] != -1) continue;
				Q.push(next);
				Dis[next.fi][next.se] = Dis[now.fi][now.se] + 1;
			}
		}
		ans = max(ans, last);
	}
	cout << ans;
	return 0;
}










