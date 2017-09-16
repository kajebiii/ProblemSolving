// =====================================================================================
//
//       Filename:  3163.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/22/2016 23:01:38
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

int N, L, K;
int main() {
	int TC; cin >> TC;
	while(TC--)
	{
		deque<pi> Ps, Ns;
		vector<pi> Ans;
		scanf("%d%d%d", &N, &L, &K);
		for(int i=0; i<N; i++)
		{
			int p, a; scanf("%d%d", &p, &a);
			Ans.pb(mp(-1, a));
			if(a > 0) Ps.pb(mp(L-p, a));
			else Ns.pb(mp(p, a));
		}
		int l = 0, r = N-1;
		for(int i=0; i<N; i++)
			if(Ps.size() == 0 || (Ns.size() != 0 && Ns.front().fi <= Ps.back().fi) ) 
			{
				Ans[l++].fi = Ns.front().fi;
				Ns.pop_front();
			}
			else 
			{
				Ans[r--].fi = Ps.back().fi;
				Ps.pop_back();
			}
		l = 0, r = N-1;
		int ans = -1;
		for(int i=0; i<K; i++)
			if(Ans[l].fi < Ans[r].fi) 
				ans = Ans[l++].se;
			else if(Ans[l].fi > Ans[r].fi)
				ans = Ans[r--].se;
			else if(Ans[l].se < Ans[r].se)
				ans = Ans[l++].se;
			else
				ans = Ans[r--].se;
		printf("%d\n", ans);
	}
	return 0;
}










