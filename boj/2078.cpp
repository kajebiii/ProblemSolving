// =====================================================================================
//
//       Filename:  2078.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 18:38:33
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
	int A, B; cin >> A >> B;
	int l = 0, r = 0;
	while(A != B)
		if(A > B) l += (A-1)/B, A = (A-1)%B + 1;
		else r += (B-1)/A, B = (B-1)%A + 1;
	printf("%d %d\n", l, r);
	return 0;
}










