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

	int TC; scanf("%d\n", &TC);
	while(TC--)
	{
		ll a, b, c; char p;
		scanf("%lld %c %lld = %lld\n", &a, &p, &b, &c);
		ll d;
		if(p == '+') d = a+b;
		if(p == '-') d = a-b;
		if(p == '*') d = a*b;
		if(p == '/') d = a/b;
		if(c == d) puts("correct");
		else puts("wrong answer");
	}
	return 0;
}