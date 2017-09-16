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

const int MAX_N = (1<<20) + 200;

int K, N, Nr[MAX_N * 2], Dis[MAX_N * 2];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> K; N = (1 << K) - 1;
	for(int i=1; i<=N*2; i++) scanf("%d", &Nr[i]);

	int ans = 0;
	for(int i=1; i<=N*2; i++) ans += Nr[i];
	for(int i=N; i>=1; i--)
	{
		int l = Nr[i*2-1], r = Nr[i*2];
		int maxV = max(Dis[i*2] + l, Dis[i*2+1] + r);
		ans += (maxV - Dis[i*2] - l) + (maxV - Dis[i*2+1] - r);
		Dis[i] = maxV;
	}
	cout << ans;
	return 0;
}