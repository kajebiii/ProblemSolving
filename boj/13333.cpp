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

const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	Nr[0] = INF;
	for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	sort(Nr+1, Nr+N+1);
	reverse(Nr+1, Nr+N+1);

	int ans = -1;
	for(int i=0; i<=N; i++)
		if(Nr[i] >= i && Nr[i+1] <= i) ans = i;
	cout << ans;

	return 0;
}