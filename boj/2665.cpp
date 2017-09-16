// =====================================================================================
//
//       Filename:  2665.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/30/2016 16:40:32
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
#include <math.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define fi first
#define se second

const int INF = 0x7fffffff;
const int CX[4] = {-1, 0, 1, 0}, CY[4] = {0, -1, 0, 1};

int N, Nr[55][55];
int Dy[2][55][55];
int main() {
	scanf("%d", &N); for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%1d", &Nr[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[0][i][j] = INF;
	Dy[0][1][1] = 0;

	int ans = INF;
	for(int k=1; k<=N*N; k++)
	{
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) Dy[k%2][i][j] = INF;
		for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
			if(Dy[1-k%2][i][j] != INF)
				for(int l=0; l<4; l++)
				{
					int x = i+CX[l], y = j+CY[l];
					if(x<=0 || y<=0 || x>N || y>N) continue;
					Dy[k%2][x][y] = min(Dy[k%2][x][y], Dy[1-k%2][i][j] + 1-Nr[i][j]);
				}
		ans = min(ans, Dy[k%2][N][N]);
	}
	cout << ans;
	return 0;
}










