// =====================================================================================
//
//       Filename:  4375.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/26/2016 10:25:25
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

int main() {	
	int N;
	while(scanf("%d", &N) != EOF)
	{
		int now = 1 % N, ans = 1;
		while(now != 0)
		{
			now *= 10; now += 1; now %= N;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}










