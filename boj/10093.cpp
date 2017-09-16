// =====================================================================================
//
//       Filename:  10093.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 00:41:55
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

ll max(ll a, ll b) {return a<b?b:a;}
int main() {
	ll A, B; cin >> A >> B;
	if(B < A) swap(A, B);
	printf("%lld\n", max(B-A-1, 0));
	for(ll i=A+1; i<=B-1; i++) printf("%lld ", i);
	return 0;
}









