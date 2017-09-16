// =====================================================================================
//
//       Filename:  1951.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/23/2016 13:07:34
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

int main() {
	ll N; cin >> N;
	ll power = 1, cnt = 1;
	ll ans = 0;
	while(power <= N)
	{
		ans += 1ll * min(power * 10 - 1 - power + 1, N - power + 1) * cnt;
		cnt++;
		power *= 10;
	}
	printf("%lld\n", ans % 1234567);
	return 0;
}










