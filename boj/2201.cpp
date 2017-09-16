// =====================================================================================
//
//       Filename:  2201.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/20/2016 16:29:06
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

ll Fi[100];
int main() {
	Fi[0] = Fi[1] = 1;
	for(int i=2; i<92; i++) Fi[i] = Fi[i-1] + Fi[i-2];
	ll N; cin >> N;

	bool first = false;
	for(int i=91; i>=1; i--)
	{
		if(Fi[i] <= N) first = true;
		if(first) printf("%d", (int)(Fi[i] <= N));
		N %= Fi[i];
	}
	return 0;
}










