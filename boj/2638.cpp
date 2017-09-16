// =====================================================================================
//
//       Filename:  2638.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 17:52:09
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
const int MAX_N = 111;

int N, M, Map[MAX_N][MAX_N];
int Chk[MAX_N][MAX_N];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
		scanf("%d", &Map[i][j]);
	int ans = 0, cnt = 0;
	while(1)
	{
		int sum = accumulate(&Map[0][0], &Map[N+1][0], 0);
		if(sum == 0) break;
		cnt = sum;
		ans++;
		queue<pi> Q;
		Q.push(mp(1, 1)); Chk[1][1] = ans;
		while(!Q.empty())
		{
			pi now = Q.front(); Q.pop();
			for(int k=0; k<4; k++)
			{
				pi next = mp(now.fi + CX[k], now.se + CY[k]);
				if(next.fi < 1 || next.fi > N || next.se < 1 || next.se > M) continue;
				if(Chk[next.fi][next.se] == ans) continue;
				if(Map[next.fi][next.se] >= 1)
				{
					Map[next.fi][next.se]++;
					continue;
				}
				Q.push(next);
				Chk[next.fi][next.se] = ans;
			}
		}
		for(int i=1; i<=N; i++) for(int j=1; j<=M; j++)
			if(Map[i][j] >= 3)
				Map[i][j] = 0;
			else if(Map[i][j] == 2)
				Map[i][j] = 1;
	}
	cout << ans;
	return 0;
}










