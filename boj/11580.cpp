// =====================================================================================
//
//       Filename:  11580.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 20:49:47
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

map<char, pi> M;
set<pi> S;
int main() {
	S.insert(mp(0, 0));
	int N; cin >> N; string L; cin >> L;
	M['S'] = mp(-1, 0); M['N'] = mp(1, 0);
	M['W'] = mp(0, 1); M['E'] = mp(0, -1);
	pi now = mp(0, 0);

	int ans = 1;
	for(char c : L)
	{
		now = now + M[c];
		if(S.count(now) == 0)
		{
			ans++;
			S.insert(now);
		}
	}
	cout << ans;
	return 0;
}










