// =====================================================================================
//
//       Filename:  1673.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/04/2016 16:14:48
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
	int N, K;
	while(scanf("%d%d", &N, &K) != EOF)
	{
		int ans = N, c = N;
		while(c >= K)
		{
			ans += c / K;
			c += c / K - c / K * K;
		}
		printf("%d\n", ans);
	}
	return 0;
}










