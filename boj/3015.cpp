// =====================================================================================
//
//       Filename:  3015.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 17:17:24
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

int N;
int main() {
	cin >> N;
	stack<pi> S; S.push(mp(INF, 0));
	ll ans = 0;
	for(int i=0; i<N; i++)
	{
		int x; scanf("%d", &x);
		while(S.top().fi < x)
		{
			ans += 1ll * S.top().se;
			S.pop();
		}
		if(S.top().fi == x)
		{
			int cnt = S.top().se; S.pop();
			ans += 1ll * cnt;
			ans += 1ll * min(1, S.top().se);
			S.push(mp(x, cnt+1));
		}
		else 
		{
			ans += 1ll * min(1, S.top().se);
			S.push(mp(x, 1));
		}
	}
	cout << ans;
	return 0;
}










