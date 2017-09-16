// =====================================================================================
//
//       Filename:  10251.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 09:27:18
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
#include <assert.h>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
const bool debug = true;
#else
const bool debug = false;
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int N, M, L, G;
int Dy[222][111][111][2];
int V[111][111][2]; // 0 ->, 1 |
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d%d%d%d", &N, &M, &L, &G);
		for(int i=0; i<N; i++) for(int j=0; j<M-1; j++) scanf("%d", &V[i][j][0]);
		for(int i=0; i<N-1; i++) for(int j=0; j<M; j++) scanf("%d", &V[i][j][1]);
		int NM = max(N, M);
		for(int k=0; k<=NM; k++) for(int i=0; i<N; i++) for(int j=0; j<M; j++) for(int l=0; l<2; l++)
			Dy[k][i][j][l] = G + 1;
		Dy[0][0][0][0] = Dy[0][0][0][1] = 0;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		{
			for(int k=0; k<=NM; k++)
			{
				if(i > 0) Dy[k][i][j][1] = min(Dy[k][i][j][1], Dy[k][i-1][j][1] + V[i-1][j][1]);
				if(j > 0) Dy[k][i][j][0] = min(Dy[k][i][j][0], Dy[k][i][j-1][0] + V[i][j-1][0]);
			}
			for(int k=1; k<=NM; k++)
			{
				if(i > 0) Dy[k][i][j][1] = min(Dy[k][i][j][1], Dy[k-1][i-1][j][0] + V[i-1][j][1]);
				if(j > 0) Dy[k][i][j][0] = min(Dy[k][i][j][0], Dy[k-1][i][j-1][1] + V[i][j-1][0]);
			}
		}
		int ans = INF;
		for(int k=0; k<=NM; k++)
			if(Dy[k][N-1][M-1][0] <= G || Dy[k][N-1][M-1][1] <= G)
			{
				ans = (N+M-2) * L + k;
				break;
			}
		if(ans == INF) ans = -1;
		if(debug) printf(">>");
		printf("%d\n", ans);
	}
	return 0;
}










