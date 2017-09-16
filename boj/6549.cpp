// =====================================================================================
//
//       Filename:  6549.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 21:45:01
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
#endif
pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};

int Nr[101101];
int main() {
	int N;
	while(scanf("%d", &N))
	{
		if(N == 0) break;
		for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
		stack<pi> S;
		S.push(mp(0, 0));

		int i = 1;
		Nr[N+1] = 0;
		ll ans = 0;
		while(i <= N + 1)
		{
			if(S.top().fi <= Nr[i])
			{
				S.push(mp(Nr[i], i));
				i++;
			}
			else
			{
				int h = S.top().fi; S.pop();
				int r = i - 1;
				int l = S.top().se + 1;
				ans = max(ans, 1ll * h * (r - l + 1));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}










