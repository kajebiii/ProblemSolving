// =====================================================================================
//
//       Filename:  12758.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/16/2016 16:10:49
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
const int MOD = 1e9 + 7;

int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		vector<pi> past, now;
		past.pb(mp(1, 1));
		int N; cin >> N;
		for(int k=0; k<N; k++)
		{
			int x; scanf("%d", &x);
			vector<int> factor;
			for(int i=1; i*i<=x; i++)
				if(x % i == 0)
				{
					factor.pb(i);
					if(i*i != x) factor.pb(x/i);
				}
			sort(factor.begin(), factor.end());

			now.clear();
			int sum = 0, ix = 0;
			for(int val : factor)
			{
				while(ix < past.size() && past[ix].fi <= val)
					sum = (sum + past[ix++].se) % MOD;
				now.pb(mp(val, sum));
			}
			swap(past, now);
		}
		int ans = 0;
		for(pi temp : past)
			ans = (ans + temp.se) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}










