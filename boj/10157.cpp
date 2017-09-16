// =====================================================================================
//
//       Filename:  10157.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/27/2016 14:19:42
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
const int CX[4] = {0, 1, 0, -1}, CY[4] = {1, 0, -1, 0};

bool Chk[1111][1111];
int main() {
	int N, M; cin >> N >> M;
	int K; cin >> K;
	int x = 1, y = 1, cnt = 1, d = 0;
	if(K > N * M)
	{
		puts("0");
		return 0;
	}
	for(int i=1; i<=N; i++) Chk[i][0] = Chk[i][M+1] = true;
	for(int i=1; i<=M; i++) Chk[0][i] = Chk[N+1][i] = true;
	while(1)
	{
		if(cnt == K)
		{
			printf("%d %d", x, y);
			break;
		}
		Chk[x][y] = true;
		
		int nx, ny;
		nx = x + CX[d];
		ny = y + CY[d];
		if(Chk[nx][ny] == true)
		{
			d = (d+1)%4;
			nx = x + CX[d];
			ny = y + CY[d];
		}
		x = nx;
		y = ny;
		cnt++;
	}
	return 0;
}










