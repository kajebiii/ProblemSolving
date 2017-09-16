// =====================================================================================
//
//       Filename:  8980.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/18/2016 16:02:18
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
const int MAX_N = 2e3 + 100;

int N, C, M, Cnt[MAX_N];
vector<pi> V[MAX_N];
int main() {
	cin >> N >> C >> M;
	for(int i=0; i<M; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		V[x].pb(mp(y, c)); 
	}
	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		ans += Cnt[i]; Cnt[i] = 0;
		for(pi l : V[i]) Cnt[l.fi] += l.se;
		int sum = accumulate(Cnt+1, Cnt+N+1, 0);
		if(sum <= C) continue;
		for(int j=N; j>=1; j--)
		{
			int minus = min(Cnt[j], sum - C);
			Cnt[j] -= minus;
			sum -= minus;
		}
	}
	cout << ans;
	return 0;
}










