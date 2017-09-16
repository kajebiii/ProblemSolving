// =====================================================================================
//
//       Filename:  2057.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 16:35:47
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

ll F[21];
int main() {
	F[0] = 1; for(int i=1; i<=20; i++) F[i] = F[i-1] * i;
	ll N; cin >> N;
	if(N == 0) {puts("NO"); return 0;}
	for(int i=20; i>=0; i--) if(F[i] <= N) N -= F[i];
	if(N == 0) puts("YES");
	else puts("NO");
	return 0;
}










