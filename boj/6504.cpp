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

int F[55], FN;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	F[0] = F[1] = 1; FN = 1;
	while(F[FN] + F[FN-1] <= 100000) F[++FN] = F[FN-1] + F[FN-2];
	int TC; cin >> TC;
	while(TC--)
	{
		int x; scanf("%d", &x);
		int ans = 0;
		for(int i=FN; i>=2; i--)
			if(x >= F[i]) x -= F[i], ans += F[i-1];
		printf("%d\n", ans);
	}
	return 0;
}