// =====================================================================================
//
//       Filename:  1081.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/24/2016 03:10:14
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

ll get(ll N, ll p, ll ix)
{
	if(N <= 0) return 0;
	if(N <= 9) return N*(N+1)/2;
	ll result = 0;
	ll l = N / p, r = N % p;
	result += l * 45 * ix * p / 10;
	result += (l-1) * l / 2 * p;
	result += l * (r+1);
	result += get(r, p/10, ix-1);
	if(debug) printf("%lld / %lld / %lld : %lld\n", N, p, ix, result);
	return result;
}
int main() {	
	ll A, B; cin >> A >> B;
	if(A > B) {puts("0"); return 0;}
	ll p = 1000000000, ix = 9;
	cout << get(B, p, ix) - get(A-1, p, ix);
	return 0;
}










