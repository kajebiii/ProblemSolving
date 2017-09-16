// =====================================================================================
//
//       Filename:  4766.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 00:51:42
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

int main() {
	double past, x; scanf("%lf", &past);
	while(1)
	{
		scanf("%lf", &x);
		if(x == 999) break;
		printf("%.2lf\n", x - past);
		past = x;
	}
	return 0;
}










