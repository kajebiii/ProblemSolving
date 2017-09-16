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

string S;
int main() {
	if(debug) freopen("input.txt", "r", stdin);
	cin >> S;

	int now = 0, minV = 0;
	for(char x : S)
	{
		if(x == ')') now--;
		else now++;
		minV = min(minV, now);
	}
	now -= minV;
	printf("%d", abs(minV) + now);
	return 0;
}