#include <stdio.h>
#include <functional>
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

const int MAX_N = 1e5 + 100;

int N, K;
ll Sum[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for(int i=1, x; i<=N; i++) scanf("%d", &x), Sum[i] = Sum[i-1] + 1ll * x;
	ll ans = 0;
	for(int i=K; i<=N; i++)
		ans = max(ans, Sum[i] - Sum[i-K]);
	cout << ans;
	return 0;
}