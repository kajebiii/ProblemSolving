// =====================================================================================
//
//       Filename:  2660.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 18:31:26
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
const int MAX_N = 55;

int V[MAX_N][MAX_N];
int S[MAX_N];
int main() {
	int N; cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(i != j) V[i][j] = INF, V[j][i] = INF;
	while(1)
	{
		int x, y; scanf("%d%d", &x, &y);
		if(x == -1 || y == -1) break;
		V[x][y] = 1;
		V[y][x] = 1;
	}
	for(int k=1; k<=N; k++) for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
		if(V[i][k] != INF && V[k][j] != INF && V[i][j] > V[i][k] + V[k][j])
			V[i][j] = V[i][k] + V[k][j];
	int ans = INF, ansCnt = 0;
	for(int i=1; i<=N; i++)
	{
		int now = V[i][max_element(V[i]+1, V[i]+N+1) - V[i]];
		S[i] = now;
		if(ans == now)
			ansCnt++;
		if(ans > now)
		{
			ans = now;
			ansCnt = 1;
		}
	}
	cout << ans << " " << ansCnt << endl;
	for(int i=1; i<=N; i++)
		if(S[i] == ans)
			printf("%d ", i);
	return 0;
}










