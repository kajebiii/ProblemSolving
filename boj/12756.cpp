// =====================================================================================
//
//       Filename:  12756.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 15:42:13
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
	int A, B, C, D; cin >> A >> B >> C >> D;
	while(B > 0 && D > 0)
	{
		B -= C;
		D -= A;
	}
	if(B <= 0 && D <= 0) puts("DRAW");
	else if(B <= 0) puts("PLAYER B");
	else puts("PLAYER A");
	return 0;
}










