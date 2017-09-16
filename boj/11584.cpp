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

int getAns(int n, ll la, ll lb, ll ra, ll rb, ll a, ll b)
{
	if(n > 10) return 11;
	if(a * lb < la * b) return n;
	if(ra * b < a * rb) return n;
	la *= 3, ra *= 3, lb *= 3, rb *= 3;
	ll m1 = (la * 2 + ra) / 3, m2 = (la + ra * 2) / 3;
	if(a * rb < m2 * b && m1 * b < a * lb) return n+1;
	if(a * rb < m2 * b)
		return getAns(n+1, la, lb, m1, rb, a, b);
	else
		return getAns(n+1, m2, lb, ra, rb, a, b);
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	int TC; cin >> TC;
	while(TC--)
	{
		ll a, b; scanf("%lld%lld", &a, &b);
		int ans = getAns(0, 0, 1, 1, 1, a, b);
		if(ans > 10) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}