// =====================================================================================
//
//       Filename:  1072.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/12/2016 17:25:00
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

int main() {
	int X, Y;
	while(scanf("%d%d", &X, &Y) != EOF)
	{
		ll Z = (1ll * Y * 100 / X);
		if(Z >= 99) {printf("-1\n"); continue;}
		ll k = (1ll * (Z+1) * X - 1ll * 100 * Y + (99 - Z - 1) ) / (99 - Z);
		printf("%lld\n", k);
	}
	return 0;
}










