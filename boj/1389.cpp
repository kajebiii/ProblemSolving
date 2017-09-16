// =====================================================================================
//
//       Filename:  1389.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 15:07:42
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

int V[111][111];

int main() {
	int N, M; cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(i != j) V[i][j] = INF;
	for(; M--; )
	{
		int x, y; scanf("%d%d", &x, &y);
		V[x][y] = V[y][x] = 1;
	}

	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] != INF && V[k][j] != INF && V[i][j] > V[i][k] + V[k][j])
			V[i][j] = V[i][k] + V[k][j];
	int minK = INF, minI = -1;
	for(int i=1; i<=N; i++)
	{
		int now = 0;
		for(int j=1; j<=N; j++)
			now += V[i][j];
		if(minK > now)
			minK = now, minI = i;
	}
	cout << minI;
	return 0;
}










