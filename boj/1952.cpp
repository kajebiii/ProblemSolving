// =====================================================================================
//
//       Filename:  1952.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/13/2016 02:02:41
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
	int N, M; cin >> N >> M;
	N -= 1; M -= 1; int minV = min(N/2, M/2);
	int ans = minV * 4; N -= minV*2; M -= minV*2;
	N += 1; M += 1;
	if(N == 1) ans += 0;
	else if(N == 2) ans += 2;
	else if(M == 1) ans += 1;
	else if(M == 2) ans += 3;
	cout << ans;
	return 0;
}










