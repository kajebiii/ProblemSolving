// =====================================================================================
//
//       Filename:  8932.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/17/2016 03:46:15
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

double myabs(double x) {return x>0?x:-x;}
int main() {
	double A[7] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
	double B[7] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
	double C[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
	int TC; cin >> TC;
	while(TC--)
	{
		int ans = 0;
		for(int i=0; i<7; i++)
		{
			double x; scanf("%lf", &x);
			ans += (int)(A[i] * pow(myabs(B[i]-x), C[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}










