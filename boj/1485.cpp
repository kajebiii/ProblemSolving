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

pi A[4];
ll dis(pi a, pi b)
{
	ll x = a.fi - b.fi, y = a.se - b.se;
	return x * x + y * y;
}
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC; cin >> TC;
	while(TC--)
	{
		for(int i=0; i<4; i++) scanf("%d%d", &A[i].fi, &A[i].se);
		pair<ll, int> B[4];
		for(int i=1; i<4; i++) B[i] = mp(dis(A[0], A[i]), i);
		sort(B+1, B+4);

		bool flag = false;
		if(B[1].fi == B[2].fi && B[1].fi * 2 == B[3].fi)
			if(dis(A[B[3].se], A[B[1].se]) == B[1].fi)
				if(dis(A[B[3].se], A[B[2].se]) == B[1].fi)
					flag = true;
		if(flag) puts("1");
		else puts("0");
	}
	return 0;
}