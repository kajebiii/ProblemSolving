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

int main() {
	if(debug) freopen("input.txt", "r", stdin);
	
	int TC; cin >> TC;

	while(TC--)
	{
		int N; scanf("%d", &N);
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			int now = 0;
			for(int j=0, x; j<3; j++)
				scanf("%d", &x), now = max(now, x);
			ans += now;
		}
		printf("%d\n", ans);
	}

	return 0;
}