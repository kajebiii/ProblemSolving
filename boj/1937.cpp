// =====================================================================================
//
//       Filename:  1937.cpp
//
//    Description:  BOJ 
//
//        Version:  1.0
//        Created:  08/26/2016 14:50:15
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
const int MAX_N = 555;

int Nr[MAX_N][MAX_N], N;
int Dis[MAX_N][MAX_N], SN;
pair<int, pi> S[MAX_N*MAX_N];

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
	{
		int x; scanf("%d", &x);
		Nr[i][j] = x;
		S[SN++] = mp(x, mp(i, j));
	}
	sort(S, S+SN);
	
	int ans = 0;
	for(int k=0; k<SN; k++)
	{
		int x = S[k].se.fi, y = S[k].se.se;
		for(int l=0; l<4; l++)
		{
			int a = x + CX[l], b = y + CY[l];
			if(a < 1 || a > N || b < 1 || b > N) continue;
			if(Nr[a][b] <= Nr[x][y]) continue;
			Dis[a][b] = max(Dis[a][b], Dis[x][y] + 1);
			ans = max(ans, Dis[a][b]);
		}
	}
	cout << ans + 1;

	return 0;
}










