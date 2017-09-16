// =====================================================================================
//
//       Filename:  1720.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 20:29:21
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

ll Dy[33]; int N;
int main() {
	cin >> N;
	Dy[0] = Dy[1] = 1;
	for(int i=2; i<=N; i++) 
		Dy[i] = Dy[i-1] + Dy[i-2] * 2;
	ll ans = Dy[N/2];
	if(N % 2 == 0) ans += 2 * Dy[N/2-1];
	cout << (Dy[N] - ans) / 2 + ans;
	return 0;
}










