// =====================================================================================
//
//       Filename:  11104.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/14/2016 02:58:17
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

int main() {
	int N; cin >> N;
	while(N--)
	{
		int power = 1<<23, ans = 0;
		for(int i=0, x; i<24; i++, power>>=1)
			scanf("%1d", &x), ans += x * power;
		printf("%d\n", ans);
	}
	return 0;
}










