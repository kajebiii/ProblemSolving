// =====================================================================================
//
//       Filename:  9339.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/15/2016 00:29:26
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
	int TC; cin >> TC;
	while(TC--)
	{
		int P, N; scanf("%d", &N);
		set<int> S; for(int i=0, x; i<N; i++) scanf("%d", &x), S.insert(x);
		scanf("%d", &P);

		int ansIx = -1, ansV = INF, cnt = 0;
		for(int i=0; i<P; i++)
		{
			int n, m, s; scanf("%d%d%d", &n, &m, &s);
			if(S.count(n) == 0) continue;
			if(m * 60 + s > 360) continue;
			if(m == -1) continue;
			cnt++;
			if(ansV > m * 60 + s)
			{
				ansV = m * 60 + s;
				ansIx = n;
			}
		}
		printf("%d %d\n", ansIx, cnt);
	}
	return 0;
}










