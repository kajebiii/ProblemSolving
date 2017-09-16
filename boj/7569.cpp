// =====================================================================================
//
//       Filename:  7569.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/25/2016 16:30:50
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
const int CX[6] = {-1, 0, 1, 0, 0, 0};
const int CY[6] = {0, -1, 0, 1, 0, 0};
const int CZ[6] = {0, 0, 0, 0, -1, 1};

int Map[111][111][111];
int Dis[111][111][111];
int M, N, K;

int main() {
	cin >> M >> N >> K;
	queue< pair<int, pi> > Q;
	int all = 0;
	for(int k=0; k<K; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				Dis[k][i][j] = -1;
				scanf("%d", &Map[k][i][j]);
				if(Map[k][i][j] >= 0)
					all++;
				if(Map[k][i][j] == 1)
				{
					Q.push(mp(k , mp(i, j)));
					Dis[k][i][j] = 0;
				}
			}
	int ans = 0;
	int cnt = 0;

	while(!Q.empty())
	{
		pair<int, pi> now = Q.front(); Q.pop();
		ans = Dis[now.fi][now.se.fi][now.se.se];
		cnt++;
		for(int k=0; k<6; k++)
		{
			pair<int, pi> next = mp(now.fi + CX[k], mp(now.se.fi + CY[k], now.se.se + CZ[k]));
			int x = next.fi, y=next.se.fi, z = next.se.se;
			if(x < 0 || x >= K || y < 0 || y >= N || z < 0 || z >= M) continue;
			if(Map[x][y][z] == -1) continue;
			if(Dis[x][y][z] != -1) continue;
			Q.push(next);
			Dis[x][y][z] = ans + 1;
		}
	}

	if(cnt != all)
		printf("-1");
	else
		printf("%d\n", ans);

	return 0;
}










