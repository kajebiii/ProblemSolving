// =====================================================================================
//
//       Filename:  2015.cpp
//
//    Description:  BOJ
//
//        Version:  1.0
//        Created:  09/10/2016 00:53:03
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
#ifdef ONLINE_JUDGE
const bool debug = false;
#else
const bool debug = true;
#endif

pi operator +(const pi &x, const pi &y) {return mp(x.fi+y.fi, x.se+y.se);}

const int INF = 0x7fffffff;
const pi Ch[4] = {mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1)};
const int MAX_N = 2e5 + 200;

int N; ll K, Memo[MAX_N];
pair<ll, int> Sum[MAX_N];
int main() {
	cin >> N >> K;
	for(ll i=1, sum=0, x; i<=N; i++) scanf("%lld", &x), sum += x, Sum[i] = mp(sum, i);
	for(int i=0; i<=N; i++) Memo[i] = Sum[i].fi;
	sort(Sum+1, Sum+N+1);
	ll ans = 0;
	for(int i=0; i<N; i++)
	{
		ll now = Memo[i];
		int ix = (int)(upper_bound(Sum+1, Sum+N+1, mp(now + K, N+1)) - lower_bound(Sum+1, Sum+N+1, mp(now + K, i+1)));
		ans += 1ll * ix;
	}
	if(debug) printf("hello!");
	cout << ans;
	return 0;
}










