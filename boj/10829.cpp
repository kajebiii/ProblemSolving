// =====================================================================================
//
//       Filename:  10829.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 23:45:35
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

void print(ll n)
{
	if(n==0) return;
	print(n/2);
	printf("%lld", n%2);
}

int main() {
	ll N; cin >> N;
	print(N);
	return 0;
}










