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
pi operator +(const pi &x, const pi &y) { return mp(x.fi+y.fi, x.se+y.se); }

const int INF = 0x7fffffff;
const pi Ch[4] ={ mp(-1, 0), mp(0, -1), mp(1, 0), mp(0, 1) };

ll gcd(ll x, ll y) { return y?gcd(y, x%y):x; }
ll findSq(ll k)
{
	ll s = 0, e = INF;
	while(s < e)
	{
		ll m = (s + e + 1) / 2;
		if(m * m <= k)
			s = m;
		else
			e = m - 1;
	}
	return e;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	ll a, b; cin >> a >> b;
	ll ans = findSq(b) - findSq(a);
	if(ans == 0) { puts("0"); return 0; }
	ll down = b - a, g = gcd(ans, down);
	ans /= g, down /= g;
	printf("%lld/%lld", ans, down);
	return 0;
}