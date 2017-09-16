// =====================================================================================
//
//       Filename:  9205.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 09:49:55
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

int P[111][2], N, V[111][111];
int Dis(int a, int b)
{
	int dx = P[a][0] - P[b][0];
	int dy = P[a][1] - P[b][1];
	return abs(dx)+abs(dy);
}
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		scanf("%d", &N);
		N += 2;
		for(int i=0; i<N; i++) scanf("%d%d", &P[i][0], &P[i][1]);
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) V[i][j] = 0;
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(Dis(i, j) <= 1000) V[i][j] = 1;
		for(int k=0; k<N; k++) for(int i=0; i<N; i++) for(int j=0; j<N; j++)
			if(V[i][k] == 1 && V[k][j] == 1) V[i][j] = 1;
		if(V[0][N-1] == 1) puts("happy"); else puts("sad");
	}
	return 0;
}










