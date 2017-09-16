// =====================================================================================
//
//       Filename:  1322.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  10/04/2016 12:18:17
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

ll X, K;
int main() {
	ll ans = 0;
	ll cnt = 0;
	cin >> X >> K;
	while(K != 0)
	{
		if(X % 2 == 0) 
		{
			if(K % 2 == 1) ans += (1ll << cnt);
			K /= 2;
		}
		X /= 2;
		cnt++;
	}
	cout << ans;
	return 0;
}










