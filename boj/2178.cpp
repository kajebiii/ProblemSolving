// =====================================================================================
//
//       Filename:  2178.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/16/2016 21:47:52
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

#define pi pair<int, int>
#define mp make_pair

using namespace std;

queue<pi> Q;
map<pi, int> S;

int N, M, Map[111][111];

int main() {
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &Map[i][j]);
	S[mp(1, 1)] = 1;
	Q.push(mp(1, 1));
	while(!Q.empty())
	{
		pi now = Q.front(); Q.pop();
		if(now == mp(N, M))
		{
			printf("%d\n", S[now]);
			return 0;
		}
		int cx[4] = {0, 1, 0, -1};
		int cy[4] = {-1, 0, 1, 0};
		for(int k=0; k<4; k++)
		{
			pi next = mp(now.first + cx[k], now.second + cy[k]);
			if(S.count(next) != 0) continue;
			if(Map[next.first][next.second] == 0) continue;
			S[next] = S[now] + 1;
			Q.push(next);
		}
	}
	return 0;
}










