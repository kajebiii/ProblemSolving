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

const int MAX_N = 1e3 + 100;

int N, W, L;
int Nr[MAX_N];

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> N >> W >> L;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);

	deque<pi> Q;
	int T = 0;
	for(int i=0; i<W; i++) Q.push_back(mp(0, -1));

	int sum = 0, ix = 0, last = -1;
	while(last != N-1)
	{
		pi now = Q.front(); Q.pop_front();
		if(now.se != -1) last = now.se;
		sum -= now.fi;
		if(sum + Nr[ix] <= L) Q.pb(mp(Nr[ix], ix)), sum += Nr[ix], ix++;
		else Q.pb(mp(0, -1));
		T++;
	}
	cout << T;
	return 0;
}