// =====================================================================================
//
//       Filename:  1987.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/23/2016 14:07:18
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

int N, M; char Map[33][33];
int Chk[33][33];
int Ans = 0;
void DFS(int x, int y, int n, int state)
{
	Ans = max(Ans, n);
	Chk[x][y] = 1;
	for(int k=0; k<4; k++)
	{
		int nx = x + CX[k], ny = y + CY[k];
		if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if(Chk[nx][ny] == 1) continue;
		int newState = (1 << (Map[nx][ny] - 'A'));
		if(state & newState) continue;
		DFS(nx, ny, n+1, newState | state);
	}
	Chk[x][y] = 0;
}

int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%s", Map[i]);

	DFS(0, 0, 1, (1 << (Map[0][0] - 'A')));
	cout << Ans;
	return 0;
}










