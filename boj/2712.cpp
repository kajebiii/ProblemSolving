// =====================================================================================
//
//       Filename:  2712.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 22:41:36
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

map<string, double> Multi;
map<string, string> Unit;
int main() {
	int T; cin >> T;
	Multi["kg"] = 2.2046;
	Multi["lb"] = 0.4536;
	Multi["l"] = 0.2642;
	Multi["g"] = 3.7854;
	Unit["kg"] = "lb"; Unit["lb"] = "kg";
	Unit["l"] = "g"; Unit["g"] = "l";
	while(T--)
	{
		double x; string S; scanf("%lf", &x); cin >> S;
		printf("%.4lf ", x*Multi[S]); cout << Unit[S]; puts("");
	}
	return 0;
}










