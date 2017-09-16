// =====================================================================================
//
//       Filename:  1753.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/24/2016 21:04:30
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
const int MAX_N = 2e4 + 200;

int N, M;
vector<pi> V[MAX_N];
int Dis[MAX_N];
int main() {
	int K;
	cin >> N >> M >> K;
	for(; M--;)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		V[x].push_back(mp(y,c));
	}
	priority_queue<pi> Q;

	fill(Dis+1, Dis+N+1, INF);
	Q.push(mp(-0, K));
	Dis[K] = 0;
	while(!Q.empty())
	{
		int now = Q.top().se, cost = -Q.top().fi; Q.pop();
		if(Dis[now] < cost) continue;
		for(pi v : V[now])
		{
			int next = v.fi, ncost = cost + v.se;
			if(Dis[next] <= ncost) continue;
			Q.push(mp(-(Dis[next] = ncost), next));
		}
	}
	for(int i=1; i<=N; i++)
		if(Dis[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", Dis[i]);
	return 0;
}










