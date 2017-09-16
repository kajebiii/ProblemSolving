// =====================================================================================
//
//       Filename:  2228.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 15:24:17
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

int N, M, Nr[111], Dy[55][111];
int main() {
	cin >> N >> M; for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<=M; i++) for(int j=0; j<=N; j++) Dy[i][j] = -INF;
	Dy[0][0] = Dy[0][1] = 0; Dy[1][1] = Nr[1];
	for(int i=2; i<=N; i++)
	{
		for(int j=1; j<=M; j++) for(int k=0; k<=i-2; k++)
			if(Dy[j-1][k] != -INF)
				Dy[j][i] = max(Dy[j][i], Dy[j-1][k] + Nr[i]);
		for(int j=1; j<=M; j++)
			if(Dy[j][i-1] != -INF)
				Dy[j][i] = max(Dy[j][i], Dy[j][i-1] + Nr[i]);
	}
	int ans = -INF;
	for(int i=0; i<=N; i++) ans = max(ans, Dy[M][i]);
	cout << ans;
	return 0;
}










