// =====================================================================================
//
//       Filename:  3035.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 21:13:56
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

char Ans[55][55];
int main() {
	int R, C, ZR, ZC; cin >> R >> C >> ZR >> ZC;
	for(int i=0; i<R; i++) scanf("%s", Ans[i]);
	for(int i=0; i<R*ZR; i++, puts("")) for(int j=0; j<C*ZC; j++)
		printf("%c", Ans[i/ZR][j/ZC]);
	return 0;
}










