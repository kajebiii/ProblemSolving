// =====================================================================================
//
//       Filename:  2688.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 17:06:52
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

ll C[99][11];
int main() {
	for(int i=0, j; i<=74; i++)
		for(C[i][0] = 1, j=1; j<=min(10, i); j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	int TC; cin >> TC;
	while(TC--)
	{
		int N; scanf("%d", &N);
		printf("%lld\n", C[N+9][9]);
	}
	return 0;
}










