// =====================================================================================
//
//       Filename:  2698.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 16:52:32
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
const pi Ch[8] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 1), mp(1, -1), mp(1, 1)};

int N, K, Dy[111][111][2];
int main() {
	int TC; cin >> TC;
	Dy[0][0][0] = 1;
	N = 100;
	for(int i=1; i<=N; i++)
	{
		for(int k=0; k<=N; k++)
			Dy[k][i][1] += Dy[k][i-1][0];
		for(int k=1; k<=N; k++)
			Dy[k][i][1] += Dy[k-1][i-1][1];
		for(int k=0; k<=N; k++)
			Dy[k][i][0] += (Dy[k][i-1][0] + Dy[k][i-1][1]);
	}
	while(TC--)
	{
		scanf("%d%d", &N, &K);
		if(N <= K) puts("0");
		else printf("%d\n", Dy[K][N][0] + Dy[K][N][1]);
	}
	return 0;
}










