// =====================================================================================
//
//       Filename:  2828.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 17:09:24
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

int N, M, Q;
int main() {
	cin >> N >> M >> Q;
	int a = 1, b = M;
	int ans = 0;
	for(int q=0; q<Q; q++)
	{
		int x; scanf("%d", &x);
		if(a<=x && x<=b) continue;
		if(x > b) {ans += x-b; a += x-b; b += x-b;}
		else {ans += a-x; b -= a-x; a -= a-x;}
	}
	cout << ans;
	return 0;
}










