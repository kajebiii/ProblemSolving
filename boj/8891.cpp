// =====================================================================================
//
//       Filename:  8891.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 14:47:24
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

pi toPI(int v)
{
	int s = 0, e = 20000;
	while(s < e)
	{
		int m = (s + e + 1) / 2;
		if(m*(m+1)/2 < v)
			s = m;
		else
			e = m - 1;
	}
	int x = v - s*(s+1)/2;
	return mp(x, s+2-x);
}
int toINT(pi v)
{
	int s = v.fi + v.se - 2; s = s * (s+1) / 2;
	return s + v.fi;
}
int main() {
	int T; cin >> T;
	while(T--)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", toINT(toPI(a) + toPI(b)));
	}
	return 0;
}










