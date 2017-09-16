// =====================================================================================
//
//       Filename:  1238.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/29/2016 17:58:30
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
const int MAX_N = 1e3 + 100;

int N, M, X;
int Dis[MAX_N][MAX_N];

int main() {
	cin >> N >> M >> X;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; Dis[i][j] = INF, j++);
	for(int i=1; i<=N; i++) Dis[i][i] = 0;
	while(M--)
	{
		int x, y, t; scanf("%d%d%d", &x, &y, &t);
		Dis[x][y] = min(Dis[x][y], t);
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(Dis[i][k] != INF && Dis[k][j] != INF)
			Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
	int ans = 0;
	for(int i=1; i<=N; i++)
		ans = max(ans, Dis[i][X] + Dis[X][i]);
	cout << ans;
	return 0;
}










