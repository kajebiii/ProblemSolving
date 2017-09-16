// =====================================================================================
//
//       Filename:  1629.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/01/2016 19:03:20
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

ll get(ll a, ll b, ll c) {return b?b%2?get(a,b^1,c)*a%c:get(a*a%c,b>>1,c):1;}

int main() {	
	ll A, B, C; cin >> A >> B >> C;
	printf("%lld", get(A, B, C));
	return 0;
}










