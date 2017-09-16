// =====================================================================================
//
//       Filename:  9501.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:38:45
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
	int T; cin >> T;
	while(T--)
	{
		int N, D; scanf("%d%d", &N, &D);
		int ans = 0;
		while(N--)
		{
			int x, f, c; scanf("%d%d%d", &x, &f, &c);
			ans += (D <= 1.0*x*f/c);
		}
		printf("%d\n", ans);
	}
	return 0;
}










