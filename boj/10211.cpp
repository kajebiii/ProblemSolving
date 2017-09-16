// =====================================================================================
//
//       Filename:  10211.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  08/31/2016 19:45:21
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
const int MAX_N = 1111;

int N, Dy[MAX_N];

int main() {
	int T; cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		int ans = -INF;
		for(int i=1; i<=N; i++)
		{
			int x; scanf("%d", &x);
			Dy[i] = max(x, Dy[i-1] + x);
			ans = max(ans, Dy[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}










