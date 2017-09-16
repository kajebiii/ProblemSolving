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

ll Big, Small;
int main() {
	if(debug) freopen("input.txt", "r", stdin);

	int TC = 3;
	while(TC--)
	{
		Big = 0; Small = 0;
		int N; scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			ll x; scanf("%lld", &x);
			Big += x / INF;
			Small += x % INF;
		}
		Big += Small / INF;
		Small %= INF;
		Small += INF;
		Big -= 1;
		Big += Small / INF;
		Small %= INF;
		if(Big == 0 && Small == 0) puts("0");
		else if(Big >= 0) puts("+");
		else puts("-");
	}

	return 0;
}