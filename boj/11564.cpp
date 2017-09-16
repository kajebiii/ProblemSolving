// =====================================================================================
//
//       Filename:  11564.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/02/2016 18:19:05
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
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int main() {
	ll K, A, B; cin >> K >> A >> B;
	ll ans = 0;
	if(A <= 0 && 0 <= B) ans = abs(A)/K + B/K + 1;
	if(0 < A) ans = abs(B)/K - abs(A-1)/K;
	if(B < 0) ans = abs(A)/K - abs(B+1)/K;
	cout << ans;
	return 0;
}










